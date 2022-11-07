/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_export_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/11/07 13:18:09 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	export_unsetting(t_vars *vars)
{
	t_token	*token;
	char	*name_to_find;
	int		p;

	token = vars->token->first->next;
	while (token != NULL)
	{
		name_to_find = ft_substr(token->cont, 0, ft_strlen(token->cont)
				- ft_strlen(ft_strchr(token->cont, '=')) + 1);
		p = ft_arrayintsrch(vars->env, name_to_find);
		if (p != 0)
			vars->env = ft_arrayrm(vars->env, vars->env[p]);
		token = token->next;
		free(name_to_find);
	}
	return (1);
}

int	export_parse(t_vars *vars)
{
	t_token	*token;

	token = vars->token->first->next;
	if (!token)
		return (-1);
	while (token)
	{
		if (ft_strchr(token->cont, '=') == NULL)
		{
			ft_putstr_fd("Invalid arguments.\n", 2);
			return (-1);
		}
		token = token->next;
	}
	return (1);
}

int	builtin_export(t_vars *vars)
{
	t_token	*token;
	int		i;

	token = vars->token->first;
	i = 0;
	if (token && !token->next)
	{
		while (vars->env[i] != NULL)
			printf("declare -x %s\n", vars->env[i++]);
		return (1);
	}
	if (export_parse(vars) == -1)
		return (1);
	if (ft_strchr(token->next->cont, '='))
		export_unsetting(vars);
	while (token && token->next)
	{
		if (ft_strchr(token->next->cont, '='))
		{
			vars->env = ft_arrayadd(vars->env,
					ft_strdup(remove_quotes(token->next->cont)));
		}
		token = token->next;
	}
	return (1);
}
