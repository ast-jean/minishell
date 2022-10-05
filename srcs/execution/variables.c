/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:26:10 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 18:23:13 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*save_varname(char *line)
{
	int		i;
	int		count;
	char	*var_name;

	i = 0;
	count = 0;
	while (line[count] && ft_isalnum(line[count]))
		count++;
	var_name = ft_calloc(count, sizeof(char));
	while (line[i] && ft_isalnum(line[i]))
	{
		var_name[i] = line[i];
		i++;
	}
	return (var_name);
}
// && ft_isalnum(*line + 1)
char	*find_var_inline(char *line)
{
	while (*line && *line != '$')
	{	
		if (*line == '\"')
		{	
			while (*line++ && *line != '\"')
			{
				if (*line == '$')
					return ((char *)line);
			}
		}
		if (*line++ == '\'')
		{
			while (*line && *line != '\'')
				line++;
			if (!*line)
				return (NULL);
			line++;
		}
		else
			line++;
	}

	printf("isalnum = %d\n*line + 1= >%c<\n",  ft_isalnum(*(line + 1)), *(line + 1));
	if (*line == '$' && ft_isalnum(*(line + 1)))
		return (printf("In\n"), (char *)line);
	else
		return (printf("NULL\n"),NULL);
}

char	*delete_var_name(int pos2, char *newline)
{
	int		i;
	char	*temp;

	i = pos2;
	while (i >= 0)
	{
		if (newline[i] == '$')
		{
			newline = ft_rmchar(newline, &newline[i--]);
			break ;
		}
		else
			newline = ft_rmchar(newline, &newline[i--]);
	}
	temp = newline;
	free(newline);
	return (temp);
}

char	*add_varcontent(char *line, char *var_name, char *var_value)
{
	char	*newline;
	char	*posstr;
	int		pos;
	int		pos2;
	int		i;

	posstr = find_var_inline(line);
	newline = malloc((ft_strlen(line) + 1) * sizeof(char));
	newline = line;
	i = -1;
	pos = 0;
	while (posstr[pos])
		pos++;
	pos--;
	pos = ft_strlen(line) - pos - 1 + ft_strlen(var_name);
	pos2 = pos;
	if (var_value)
		while (var_value[++i])
			newline = ft_addchar(newline, var_value[i], &newline[pos++]);
	newline = delete_var_name(pos2, newline);
	return (newline);
}

char	*check_var(char *line, t_vars *vars)
{
	char	*var_name;
	char	*var_value;
	char	*newline;

	newline = malloc(ft_strlen(line) * sizeof(char));
	newline = ft_strcpy(newline, line);
	printf("------START-----\n");
	while (printf("var_inline in while:\n") && find_var_inline(newline))
	{
		printf("line = %s\n", newline);
		var_name = save_varname(find_var_inline(newline) + 1);
		var_value = ft_getenv(vars->env, var_name);
		newline = add_varcontent(newline, var_name, var_value);
		printf("line after= %s\n", newline);
	}
	printf("------END-----\n");
	return (newline);
}
