/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset+export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:56:52 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/03 15:29:30 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// NOTE: Built-ins 2/3 (Unset + Export)

int	builtin_unset(t_vars *vars)
{
	t_token *token;
	char	*name_to_find;
	int		p;
	
	// int	i = 0;
	token = vars->token->first->next;
	while (token)
	{
		// dprintf(1, "%d\n", i++);
		// dprintf(1, "%s\n", token->next->cont);
		name_to_find = ft_strjoin(token->cont, "=");
		p = ft_arrayintsrch(vars->env, name_to_find);
		vars->env = ft_arrayrm(vars->env, vars->env[p]);
		token = token->next;
	/*debug*/ft_arrayprint(vars->env);
	}
	return (1);
}

// int	builtin_export(t_token *token, t_vars *vars)
// {
// 	char	*content;

// 	content = "";
// 	if (ft_strchr(token->next->cont, '='))
// 	{
// 		content = remove_quotes(token->next->cont);
// 		vars->env = ft_arrayadd(vars->env, content);
// 	// /*debug*/ft_arrayprint(vars->env);
// 	}
// 	else
// 	{
// 	/*debug*/printf("\033[41mError with export command\033[0m\n");
// 	}
// 	return (1);
// }

int	builtin_export(t_vars *vars)
{
	t_token	*token;
	char	*content;

	token = vars->token->first;
	content = NULL;
	while (token && token->next)
	{
	// /*DEBUG*/ dprintf(1, "%s\n", token->next->cont);
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
	token = token->next;
	}
	return (1);
}




