/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:01:25 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/03 13:49:31 by ast-jean         ###   ########.fr       */
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

void	disable_echo(void)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
}

void	ctrl_d(t_vars *vars)
{
	vars->token = NULL;
	quit_shell(vars, 0);
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
	disable_echo();
	init_shell(&vars, env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline(prompt);
		if (!line)
			ctrl_d(&vars);
		else if (ft_strcmp(line, "") != 0)
			add_history(line);
		parse_and_exec(line, &vars, env);
		remove_tmp_files(&vars);
	}
	quit_shell(&vars, 0);
	return (0);
}
