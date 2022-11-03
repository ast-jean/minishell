/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:42:14 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/03 13:50:18 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tokens(t_vars *vars)
{
	t_token	*temp;
	t_token	*temp2;

	if(vars && vars->token)
		temp = vars->token->first;
	else 
		temp = vars->token;
	while (temp)
	{
		free(temp->cont);
		temp2 = temp;
		temp = temp->next;
		free((temp2));
	}
}

void	quit_shell(t_vars *vars, int exit_code)
{
	while (vars && vars->token)
		vars->token = remove_token(vars->token, vars);
	ft_putstr_fd("exit\n", 2);
	if (vars->env)
		free2d(vars->env);
	if (vars->path_array)
		free2d(vars->path_array);
	rl_clear_history();
	exit(exit_code);
}
