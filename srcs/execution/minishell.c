/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:58:05 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/26 13:29:02 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	vars->oldpwd = getenv("OLDPWD");
	vars->path_array = NULL;
	vars->token = NULL;
	vars->last_output = 0;
	vars->heredoc_count = 0;
	vars->pid_count = 0;
	vars->pipe_count = 0;
	printf("*******************************\n");
	printf("*          MINISHELL          *\n");
	printf("*******************************\n");
}

// TOFIX : rename for check_token_type
void	parse_and_exec(char *line, t_vars *vars, char **env)
{
	if (ft_strlen(line) == 0)
		return ;
	if (!creating_tokens(line, vars))
	{
		if (!check_here(vars))
			return ;
		if (parsing_pipes(vars) == -1)
			return ;
		fd_catch(vars, vars->token->first, env);
	}
}

int	get_error(int status)
{
	if (!status)
	{
		if (errno)
			return (errno);
	}
	else
		return (status / 256);
	return (0);
}

void	handler(int sig)
{
	int	pid;

	pid = getpid();
	if (pid > 0)
	{
		if (sig == SIGINT)
		{
			ft_putstr_fd("\n", 2);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}
