/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:02:56 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/03 12:11:33 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (current && current->next)
			quit_shell(vars, ft_atoi(current->next->cont));
		else
			quit_shell(vars, 0);
	}
	return (-1);
}

void	put_cmd_not_found(t_token *current, t_vars *vars)
{
	char	*line;

	line = check_var(current->cont, vars);
	ft_putstr_fd(remove_quotes(line), 2);
	ft_putstr_fd(": cmd not found\n", 2);
	free(line);
	exit(127);
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
			if (accessing(vars, current) == -1 \
			&& is_bi_nopipes(current, vars, env) == -1)
				put_cmd_not_found(current, vars);
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
		i++;
		current = skip_group(group, vars);
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
