/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/11/02 14:16:01 by ast-jean         ###   ########.fr       */
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

t_token	*is_n_bool(t_token *current, t_vars *vars)
{
	char	*n_dup;

	vars->n = false;
	current = current->next;
	if (current)
	{
		n_dup = ft_strdup(current->cont);
		remove_quotes(n_dup);
		while (current && is_n(n_dup))
		{
		// printf("current->cont = %s\n", current->cont);
			vars->n = true;
			current = current->next;
			free(n_dup);
			n_dup = ft_strdup(current->cont);
		}
		free(n_dup);
	}
	return (current);
}

int	builtin_echo(t_token *current, t_vars *vars)
{
	char	*varstr;

	vars->gn = current->group_num;
	current = is_n_bool(current, vars);
	while (current && current->group_num == vars->gn \
	&& ft_strcmp(current->cont, "|") != 0)
	{
		varstr = check_var(current->cont, vars);
		ft_putstr_fd(remove_quotes(varstr), 1);
		free(varstr);
		if (current->next != NULL && current->next->group_num == vars->gn)
			write(1, " ", 1);
		current = current->next;
	}
	vars->last_output = 0;
	if (vars->n == false)
		ft_putstr_fd("\n", 1);
	return (1);
}
