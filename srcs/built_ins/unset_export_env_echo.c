/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_export_env_echo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/28 16:53:31 by ast-jean         ###   ########.fr       */
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
			content = remove_quotes(token->next->cont);
			vars->env = ft_arrayadd(vars->env, content);
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
	int		gn;
	char	*varstr;
	char	*str;

	gn = current->group_num;
	n = false;
	current = current->next;
	debug_print_tokens(vars);
	str = ft_strdup(current->cont);
	while (current && is_n(remove_quotes(current->cont)))
	{
		n = true;
		current = current->next;
	}
	debug_print_tokens(vars);
	while (current && current->group_num == gn
		&& ft_strcmp(current->cont, "|") != 0)
	{
		varstr = check_var(str, vars);
		printf("in builtin >%s<\n", varstr);
		ft_putstr_fd(remove_quotes(varstr), 1);
		free(varstr);
		if (current->next != NULL && current->next->group_num == gn)
			write(1, " ", 1);
		current = current->next;
	}
	free(str);
	vars->last_output = 0;
	if (n == true)
		return (1);
	else
		ft_putstr_fd("\n", 1);
	return (1);
}
