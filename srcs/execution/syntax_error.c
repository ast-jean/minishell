/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:23:33 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 13:25:55 by xchouina         ###   ########.fr       */
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
	char	*var_value;

	var_value = NULL;
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] == varname[j])
			j++;
		if (env[i][j] == '=')
		{
			j = (int)ft_strlen(varname) + 1;
			while (env[i][j])
			{	
				var_value = ft_addchar(var_value, env[i][j], &var_value[j]);
				j++;
			}
			return (var_value);
		}
	}
	return (var_value);
}
