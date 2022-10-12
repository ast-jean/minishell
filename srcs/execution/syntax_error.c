/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:23:33 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/12 15:33:53 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	syntax_error(char *token)
{
	if (!ft_strcmp(token, ""))
		printf("minishell: syntax error near unexpected token 'newline'\n");
	else
		printf("minishell: syntax error near unexpected token '%s'\n", token);
	return (0);
}

int	is_exception(t_token *token)
{
	if (!token->next)
		return (syntax_error("newline"));
	token = token->next;
	if ((token->cont[0] == '<') || (token->cont[0] == '>')
		|| (token->cont[0] == '|'))
		return (syntax_error(token->cont));
	return (1);
}

char	*ft_getenv(char **env, char *varname)
{
	int		i;
	int		j;
	int		k;
	char	*var_value;

	i = -1;
	var_value = NULL;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] == varname[j])
			j++;
		if (env[i][j] == '=' && !varname[j])
		{
			k = 0;
			j = (int)ft_strlen(varname) + 1;
			var_value = ft_calloc(ft_strlen(&env[i][j]), sizeof(char));
			while (env[i][j])
				var_value = ft_charadd(var_value, env[i][j++], &var_value[k++]);
			return (var_value);
		}
	}
	return (var_value);
}
