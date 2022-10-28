/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:02:56 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/28 10:46:31 by mjarry           ###   ########.fr       */
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

int	is_builtin(t_token *current, t_vars *vars)
{
	if (current && !ft_strcmp(remove_quotes(current->cont), "pwd"))
		return (builtin_pwd(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "env"))
		return (builtin_env(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "echo"))
		return (builtin_echo(current, vars));
	return (-1);
}

void	actually_forking(t_token *current, t_vars *vars, char **env)
{
	vars->pid[vars->pid_count] = fork();
	if (vars->pid[vars->pid_count++] == 0)
	{
		signal(SIGINT, handler_exec);
		signal(SIGQUIT, SIG_DFL);
		// dprintf(2, "fdi: %d\n", vars->fdi);
		// dprintf(2, "fdo: %d\n", vars->fdo);
		if (vars->fdi != 0)
			dup2(vars->fdi, 0);
		if (vars->fdo != 1)
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

void	fd_catch(t_vars *vars, t_token *current, char **env)
{
	int	i;
	int	group;
	int	act;
	
	vars->pid_count = 0;
	act = 0;
	if (vars->pipe_count > 0)
		act = WNOHANG;
	finding_paths(vars);
	group = current->group_num;
	vars->fdrd[0] = finding_redirs(current, redirect_input(current, 0), vars, env);
	current = skip_group(group, vars);
	i = 0;
	while ((i < vars->pipe_count) && (vars->pid_count < 32766))
	{
		group = current->group_num;
		finding_paths(vars);
		vars->fdrd[i + 1] = finding_redirs(current, redirect_input(current, vars->fdrd[i]), vars, env);
		current = skip_group(group, vars);
		i++;
	}
	while (i > 0)
		close(vars->fdrd[--i]);
	i = 0;
	// dprintf(2, "pidcount = %d\n", vars->pid_count);
	while (i <= (vars->pid_count - 1))
	{
		// close_fds(vars->fdi, vars->fdo, 0);
		if (i == vars->pipe_count)
			act = 0;
		// dprintf(2, "i :%d\n", i);
		// dprintf(2, "act: %d\n", act);
		// dprintf(2, "token: %s\n", current->cont);
		waitpid(vars->pid[i++], &vars->status, act);
		vars->last_output = get_error(vars->status);
	}
	// close_fds(vars->fdi, vars->fdo, 0);
	signal(SIGINT, handler);
}
