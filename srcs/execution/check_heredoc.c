/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:56:27 by xchouina          #+#    #+#             */
/*   Updated: 2022/11/02 18:18:18 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handler_here(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 0);
		exit(0);
		rl_redisplay();
		rl_replace_line("", 1);
		rl_on_new_line();
		ft_putstr_fd("\n", 0);
	}
}

void	in_child(t_vars *vars, char *delim, int fd)
{
	char	*line;
	char	*prompt;

	signal(2, handler_here);
	while (ft_strcmp(delim, vars->line))
	{	
		if (ft_strcmp(" ", vars->line))
		{
			line = check_var(vars->line, vars);
			vars->line = ft_strjoin(line, "\n");
			ft_putstr_fd(vars->line, fd);
			free(line);
			free(vars->line);
		}
		rl_on_new_line();
		prompt = ft_strjoin(delim, "> ");
		vars->line = readline(prompt);
		if (!vars->line)
			vars->line = delim;
		free(prompt);
	}
}

void	forking(t_vars *vars, char *delim, char *name)
{
	int	pid;
	int	stat;
	int	fd;

	pid = fork();
	signal(2, SIG_IGN);
	if (pid == 0)
	{
		fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
		in_child(vars, delim, fd);
		close(fd);
		exit(0);
	}
	else
		waitpid(pid, &stat, 0);
}

t_token	*check_heredocs(t_token *current, t_vars *vars)
{
	char	*delim;
	char	*name;
	char	*num;

	vars->line = " ";
	if (!is_exception(current))
		return (NULL);
	num = ft_itoa(vars->heredoc_count);
	name = ft_strjoin(".tmp/temp_heredoc", num);
	free(num);
	delim = remove_quotes(current->next->cont);
	new_token_after(current, name);
	forking(vars, delim, name);
	signal(2, handler);
	current = remove_token(current, vars);
	current = remove_token(current->next, vars);
	if (current == NULL)
		current = last_token(current, vars);
	return (current);
}
