/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:42:14 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/25 10:42:30 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tokens(t_vars *vars)
{
	t_token	*temp;

	temp = vars->token->first;
	while (vars && temp)
	{
		free(temp->cont);
		temp = temp->next;
		free((temp->prev));
	}
}

void	quit_shell(t_vars *vars)
{
	ft_putstr_fd("exit\n", 2);
	if (vars->env)
		free2d(vars->env);
	if (vars->path_array)
		free2d(vars->path_array);
	rl_clear_history();
	exit(0);
}
