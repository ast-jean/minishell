/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset+export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:56:52 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/03 10:57:27 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// NOTE: Built-ins 2/3 (Unset + Export)

int	builtin_unset(t_vars *vars, char *var_name)
{
	char	*name_to_find;

	name_to_find = ft_strjoin(var_name, "=");
	ft_arrayrm(vars->env, ft_arraysrch(vars->env, name_to_find));
	return (1);
}

int	builtin_export(t_token *token, t_vars *vars)
{
	char	*content;

	content = "";
	if (ft_strchr(token->next->cont, '='))
	{
		content = remove_quotes(token->next->cont);
		vars->env = ft_arrayadd(vars->env, content);
	// /*debug*/ft_arrayprint(vars->env);
	}
	else
	{
	/*debug*/printf("\033[41mError with export command\033[0m\n");
	}
	return (1);
}
