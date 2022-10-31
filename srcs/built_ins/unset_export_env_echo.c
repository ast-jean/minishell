/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_export_env_echo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:59 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/31 14:42:36 by mjarry           ###   ########.fr       */
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

	vars->gn = current->group_num;
	n = false;
	current = current->next;
	str = ft_strdup(current->cont);
	while (current && is_n(remove_quotes(current->cont)))
	{
		n = true;
		current = current->next;
	}
	while (current && current->group_num == vars->gn
		&& ft_strcmp(current->cont, "|") != 0)
	{
		varstr = check_var(current->cont, vars);//
		ft_putstr_fd(varstr, 1);// remove_quotes(varstr);
		free(varstr);// HAVE TO DO THIS ONLY ONCE!
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
