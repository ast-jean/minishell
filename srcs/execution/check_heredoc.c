/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:56:27 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 13:56:29 by xchouina         ###   ########.fr       */
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
	signal(2, handler_here);
	while (ft_strcmp(delim, vars->line))
	{	
		if (ft_strcmp(" ", vars->line))
		{
			vars->line = ft_strjoin(check_var(vars->line), "\n");
			ft_putstr_fd(vars->line, fd);
		}
		rl_on_new_line();
		vars->line = readline(ft_strjoin(delim, "> "));
		if (!vars->line)
			vars->line = delim;
	}
	usleep(10);
}

void	*check_heredocs(t_token *current, t_vars *vars)
{
	char	*delim;
	char	*name;
	int		fd;
	int		pid;
	int		stat;

	vars->line = " ";
	if (!is_exception(current))
		return (NULL);
	name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
	delim = remove_quotes(current->next->cont);
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	new_token_after(current, name);
	pid = fork();
	signal(2, SIG_IGN);
	if (pid == 0)
		in_child(vars, delim, fd);
	else
		waitpid(pid, &stat, 0);
	if (pid == 0)
		exit(0);
	signal(2, handler);
	current = remove_token(current, vars);
	current = remove_token(current->next, vars);
	if (current == NULL)
		current = last_token(current, vars);
	return (current);
}
