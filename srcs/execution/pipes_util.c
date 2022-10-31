/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:16:51 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/31 18:27:25 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	close_fds(int fdi, int fdo, int to_return)
{
	if (fdi != 0)
		close(fdi);
	if (fdo != 1)
		close(fdo);
	return (to_return);
}

t_token	*skip_group(int group, t_vars *vars)
{
	t_token	*current;

	current = vars->token->first;
	while (current && current->group_num <= group)
		current = remove_token(current, vars);
	return (current);
}

void	format_execve(t_vars *vars, t_token *token)
{
	t_token	*current;
	int		i;

	current = token;
	i = 0;
	vars->ac = 0;
	vars->av = NULL;
	while (current && current->group_num == token->group_num)
	{
		vars->ac++;
		current = current->next;
	}
	vars->av = malloc(sizeof(char *) * (vars->ac + 1));
	vars->av[i] = remove_quotes(token->cont);
	while (++i < vars->ac)
	{
		vars->av[i] = remove_quotes(check_var(token->next->cont, vars));
		token = token->next;
	}
	vars->av[i] = NULL;
	execve(vars->path, vars->av, vars->env);
	exit(errno);
}

int	finding_redirs(t_token *current, int fdi, t_vars *vars, char **env)
{
	int	pipefd[2];

	pipefd[0] = 0;
	vars->fdi = fdi;
	if (current->group_num < (vars->pipe_count + 1) && vars->pipe_count > 0)
	{
		pipe(pipefd);
		vars->fdo = redirect_output(current, pipefd[1]);
	}
	else
		vars->fdo = redirect_output(current, 1);
	current = rm_redir(current, vars);
	if (vars->fdi == -1)
	{
		ft_putstr_fd(": no such file or directory\n", 2);
		write(pipefd[1], "", 0);
		return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
	}
	if (current && is_bi_nopipes(current, vars, env) >= 1)
		return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
	else
		actually_forking(current, vars, env);
	return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
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
