/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:58:05 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/31 13:51:10 by mjarry           ###   ########.fr       */
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

void	quotes_and_var(t_vars *vars)
{
	char	*varstr;
	t_token	*current;
	
	current = vars->token->first;
	while (current)
	{
		varstr = check_var(current->cont, vars);
		remove_quotes(varstr);
		// free(varstr);
		current = current->next;
	}
}

void	parse_and_exec(char *line, t_vars *vars, char **env)
{
	if (ft_strlen(line) == 0)
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
		// quotes_and_var(vars);
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

void	disable_echo()
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
}