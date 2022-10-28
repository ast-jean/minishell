/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:16:51 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/28 15:32:30 by xchouina         ###   ########.fr       */
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
		vars->av[i] = remove_quotes(token->next->cont);
		token = token->next;
	}
	vars->av[i] = NULL;
	execve(vars->path, vars->av, vars->env);
	current = skip_group(current->group_num, vars);
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
