/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/03 10:55:00 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// NOTE: Built-ins 3/4 (Echo)
int	is_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_vars *vars)
{
	t_token	*token;
	bool	n;

	n = false;
	token = vars->token->next;
	while (is_n(remove_quotes(token->cont)))
	{
		n = true;
		token = token->next;
	}
	while (token && ft_strcmp(token->cont, "|") != 0)
	{
		ft_putstr_fd(remove_quotes(check_var(token->cont)), 1);
		if (token->next != NULL)
			write(1, " ", 1);
		token = token->next;
	}
	if (n == true)
		return (0);
	else
		ft_putstr_fd("\n", 1);
	return (0);
}
