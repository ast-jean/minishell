/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:58:05 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/03 11:32:32 by ast-jean         ###   ########.fr       */
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

int	just_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && (str[i] == ' ' || str[i] == 9))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	parse_and_exec(char *line, t_vars *vars, char **env)
{
	if (ft_strlen(line) == 0)
		return ;
	if (just_space(line) == 1)
		return ;
	if (!creating_tokens(line, vars))
	{
		if (!check_here(vars))
		{
			free_tokens(vars);
			return ;
		}
		if (parsing_pipes(vars) == -1)
		{
			free_tokens(vars);
			return ;
		}
		fd_catch(vars, vars->token->first, env);
	}
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

void	handler_exec(int sig)
{
	(void)sig;
}
