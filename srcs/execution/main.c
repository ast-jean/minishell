/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:01:25 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/25 10:21:54 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_tmp_files(t_vars *vars)
{
	int		i;
	char	*filename;
	char	*num;

	i = -1;
	while (++i <= vars->heredoc_count)
	{	
		num = ft_itoa(i);
		filename = ft_strjoin(".tmp/temp_heredoc", num);
		unlink(filename);
		free(num);
		free(filename);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_vars	vars;	
	char	*line;
	char	*prompt;

	if (argc != 1)
		return (-1);
	(void)argv;
	prompt = "$>";
	line = NULL;
	init_shell(&vars, env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline(prompt);
		if (!line)
			quit_shell(&vars);
		else if (ft_strcmp(line, "") != 0)
			add_history(line);
		parse_and_exec(line, &vars, env);
		remove_tmp_files(&vars);
	}
	quit_shell(&vars);
	return (0);
}
