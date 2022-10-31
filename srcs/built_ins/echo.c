/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/31 18:21:04 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	builtin_echo(t_token *current, t_vars *vars)
{
	bool	n;
	char	*varstr;
	char	*str;
	char	*n_dup;

	vars->gn = current->group_num;
	n = false;
	current = current->next;
	str = ft_strdup(current->cont);
	n_dup = ft_strdup(current->cont);
	while (current && is_n(remove_quotes(n_dup)))
	{
		n = true;
		current = current->next;
	}
	free(n_dup);
	while (current && current->group_num == vars->gn
		&& ft_strcmp(current->cont, "|") != 0)
	{
		varstr = check_var(current->cont, vars);
		ft_putstr_fd(remove_quotes(varstr), 1);
		free(varstr);
		if (current->next != NULL && current->next->group_num == vars->gn)
			write(1, " ", 1);
		current = current->next;
	}
	free(str);
	vars->last_output = 0;
	if (n == false)
		ft_putstr_fd("\n", 1);
	return (1);
}
