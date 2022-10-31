/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:02:56 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/31 15:01:40 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handler_exec(int sig)
{
	(void)sig;
}

int	is_bi_nopipes(t_token *current, t_vars *vars, char **env)
{
	if (vars->pipe_count > 0)
	{
		if (current && (!ft_strcmp(remove_quotes(current->cont), "export")
				|| !ft_strcmp(remove_quotes(current->cont), "unset")
				|| !ft_strcmp(remove_quotes(current->cont), "cd")
				|| !ft_strcmp(remove_quotes(current->cont), "exit")))
			return (-2);
		return (-1);
	}
	if (current && !ft_strcmp(remove_quotes(current->cont), "export"))
		return (builtin_export(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "unset"))
		return (builtin_unset(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "cd"))
		return (builtin_cd(vars, env));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "exit"))
	{
		close_fds(vars->fdi, vars->fdo, 0);
		current = skip_group(current->group_num, vars);
		quit_shell(vars);
	}
	return (-1);
}

void	actually_forking(t_token *current, t_vars *vars, char **env)
{
	vars->pid[vars->pid_count] = fork();
	if (vars->pid[vars->pid_count++] == 0)
	{
		signal(SIGINT, handler_exec);
		signal(SIGQUIT, SIG_DFL);
		dup2(vars->fdi, 0);
		dup2(vars->fdo, 1);
		close_fds(vars->fdi, vars->fdo, 0);
		if (is_builtin(current, vars) == -1)
		{
			if (accessing(vars, current) == -1
				&& is_bi_nopipes(current, vars, env) == -1)
			{
				ft_putstr_fd(remove_quotes(current->cont), 2);
				ft_putstr_fd(": cmd not found\n", 2);
				current = skip_group(current->group_num, vars);
				exit(1);
			}
			else
				format_execve(vars, current);
		}
		exit(0);
	}
	else
		signal(SIGINT, SIG_IGN);
}

void	catch_loops(t_vars *vars, t_token *current, char **env)
{
	int	i;
	int	group;

	i = 0;
	while ((i < vars->pipe_count) && (vars->pid_count < 32766))
	{
		group = current->group_num;
		finding_paths(vars);
		vars->fdrd[i + 1] = finding_redirs(current,
				redirect_input(current, vars->fdrd[i]), vars, env);
		current = skip_group(group, vars);
		i++;
	}
	while (i > 0)
		close(vars->fdrd[--i]);
}

void	fd_catch(t_vars *vars, t_token *current, char **env)
{
	int	i;
	int	group;

	vars->pid_count = 0;
	finding_paths(vars);
	group = current->group_num;
	vars->fdrd[0] = finding_redirs(current,
			redirect_input(current, 0), vars, env);
	current = skip_group(group, vars);
	catch_loops(vars, current, env);
	i = 0;
	while (i <= (vars->pid_count - 1))
	{
		waitpid(vars->pid[i++], &vars->status, 0);
		vars->last_output = get_error(vars->status);
	}
	signal(SIGINT, handler);
}
