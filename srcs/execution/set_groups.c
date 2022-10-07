/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:22:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 13:23:01 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	init_groups(t_vars *vars)
{
	t_token	*copy;
	int		i;

	vars->pipe_count = 0;
	copy = vars->token->first;
	i = 1;
	while (copy)
	{
		while (copy && ft_strcmp(copy->cont, "|") != 0)
		{
			copy->group_num = i;
			copy = copy->next;
		}
		if (copy && ft_strcmp(copy->cont, "|") == 0)
		{
			(vars->pipe_count)++;
			copy = remove_token(copy, vars);
		}
		i++;
	}
	if (vars->pipe_count >= (i - 1))
		return (-1);
	return (0);
}

int	parsing_error(void)
{
	write(2, "Error.\n", 7);
	return (-1);
}

int	parsing_pipes(t_vars *vars)
{
	t_token	*cpy;

	cpy = vars->token->first;
	if (cpy->cont[0] == '|')
		parsing_error();
	while (cpy->next)
	{
		if ((ft_strcmp(cpy->cont, "|") == 0
				&& ft_strcmp(cpy->next->cont, "|") == 0))
			parsing_error();
		else if (cpy->cont[0] == '|' && cpy->cont[1] == '|')
			parsing_error();
		cpy = cpy->next;
	}
	if (init_groups(vars) == -1)
		parsing_error();
	return (0);
}
