/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:17:42 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/11 13:23:43 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// NOTE: Redirections ( > , < , >>)

int	redirect_input(t_token *token, int fd_init)
{
	int	group;
	int	fd;
	char *temp;

	temp = remove_quotes(token->next->cont);
	group = token->group_num;
	fd = fd_init;
	while (token && token->next && token->group_num == group)
	{
		if (ft_strcmp(token->cont, "<") == 0)
		{
			if (fd != 0)
				close(fd);
			fd = open(temp, O_RDONLY);
			if (fd == -1)
				ft_putstr_fd(temp, 2);
		}
			token = token->next;
	}
	free(temp);
	return (fd);
}

int	redirect_output(t_token *token, int fd_init)
{
	int		group;
	int		fd;
	char	*temp;

	group = token->group_num;
	fd = fd_init;
	temp = remove_quotes(token->next->cont);
	while (token && token->next && token->group_num == group)
	{
		if (ft_strcmp(token->cont, ">") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(temp,
					O_TRUNC | O_CREAT | O_RDWR, 0777);
		}
		else if (ft_strcmp(token->cont, ">>") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(temp,
					O_APPEND | O_CREAT | O_RDWR, 0777);
		}
			token = token->next;
	}
	free(temp);
	return (fd);
}

t_token	*rm2tokens(t_token *token, t_vars *vars)
{
	token->next = remove_token(token->next, vars);
	token = remove_token(token, vars);
	return (token);
}

t_token	*rm_redir(t_token *token, t_vars *vars)
{
	int	group;
	char *temp;

	group = token->group_num;
	temp = remove_quotes(token->cont);
	while (token && token->next && token->next->group_num == group)
	{
		if (ft_strcmp(token->cont, "<") == 0)
			token = rm2tokens(token, vars);
		else if (ft_strcmp(temp, ">") == 0)
			token = rm2tokens(token, vars);
		else if (ft_strcmp(temp, ">>") == 0)
			token = rm2tokens(token, vars);
		else
			token = token->next;
	}
	token = vars->token->first;
	while (token->group_num != group)
		token = token->next;
	free(temp);
	return (token);
}
