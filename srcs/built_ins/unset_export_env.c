/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_export_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/31 18:22:59 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_unset(t_vars *vars)
{
	t_token	*token;
	char	*name_to_find;
	int		p;

	token = vars->token->first->next;
	while (token != NULL)
	{
		name_to_find = ft_strjoin(token->cont, "=");
		p = ft_arrayintsrch(vars->env, name_to_find);
		if (p != 0)
			vars->env = ft_arrayrm(vars->env, vars->env[p]);
		token = token->next;
	}
	return (1);
}

int	builtin_export(t_vars *vars)
{
	t_token	*token;
	char	*content;
	int		i;

	token = vars->token->first;
	i = 0;
	if (token && !token->next)
	{
		while (vars->env[i] != NULL)
			printf("declare -x %s\n", vars->env[i++]);
		return (1);
	}
	content = NULL;
	while (token && token->next)
	{
		if (ft_strchr(token->next->cont, '='))
		{
			content = ft_strdup(remove_quotes(token->next->cont));
			vars->env = ft_arrayadd(vars->env, content);
			ft_arrayprint(vars->env);
		}
		token = token->next;
	}
	return (1);
}

int	builtin_env(t_vars *vars)
{
	if (vars->env)
		ft_arrayprint(vars->env);
	return (1);
}
