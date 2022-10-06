/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/05 17:42:48 by ast-jean         ###   ########.fr       */
=======
/*   Updated: 2022/10/06 11:18:43 by xchouina         ###   ########.fr       */
>>>>>>> main
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

int	builtin_echo(t_token *current)
{
	// t_token	*token;
	bool	n;
	int		gn;

	gn = current->group_num;
	n = false;
	current = current->next;
	while (current && is_n(remove_quotes(current->cont)))
	{
		n = true;
		current = current->next;
	}
	while (current && current->group_num == gn && ft_strcmp(current->cont, "|") != 0)
	{
		ft_putstr_fd(remove_quotes(check_var(current->cont)), 1);
		if (current->next != NULL)
			write(1, " ", 1);
		current = current->next;
	}
	if (n == true)
		return (0);
	else
		ft_putstr_fd("\n", 1);
	return (0);
}
