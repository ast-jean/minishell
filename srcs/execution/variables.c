/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:26:10 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/25 14:40:21 by ast-jean         ###   ########.fr       */
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
	if (line[count] == '?')
		return ("?");
	while (line[count] && ft_isalnum(line[count]))
		count++;
	var_name = ft_calloc(count + 1, sizeof(char));
	while (line[i] && ft_isalnum(line[i]))
	{
		var_name[i] = line[i];
		i++;
	}
	line = ft_strcpy(line, var_name);
	free(var_name);
	return (line);
}

char	*find_var_inline(char *line)
{
	while (*line && *line != '$')
	{	
		if (*line == '\"')
		{	
			while (*line++ && *line != '\"')
			{
				if (*line == '$' && (ft_isalnum(*(line + 1)) 
					|| *(line + 1) == '?'))
					return ((char *)line);
			}
		}
		if (*line == '\'')
		{
			while (*line++ && *line != '\'')
				line++;
			if (!*line)
				return (NULL);
		}
		line++;
	}
	if (*line == '$' && (ft_isalnum(*(line + 1)) || *(line + 1) == '?'))
		return ((char *)line);
	else
		return (NULL);
}

char	*delete_var_name(int pos2, char *str)
{
	int		i;
	char	*newline;
	i = pos2;

	newline = calloc(ft_strlen(str) + 1, sizeof(char));
	newline = ft_strcpy(newline, str);

	while (i >= 0)
	{
		if (newline[i] == '$')
		{
			newline = ft_charrm(newline, &newline[i--]);
			break ;
		}
		else
			newline = ft_charrm(newline, &newline[i--]);
	}
	free(str);
	return (newline);
}

char	*add_varcontent(char *line, char *var_name, char *var_value)
{
	char	*newline;
	int		pos;
	int		pos2;
	int		i;

	newline = calloc(ft_strlen(line) + 1, sizeof(char));
	newline = ft_strcpy(newline, line);
	i = -1;
	pos = ft_strlen(line) - ft_strlen(find_var_inline(line)) + ft_strlen(var_name);
	pos2 = pos;
	if (var_value)
		while (var_value[++i])
			newline = ft_charadd(newline, var_value[i], &newline[pos++]);
	newline = delete_var_name(pos2, newline);
	printf("line >%s<\nnewline >%s<\n", line, newline);
	free(line);
	return (newline);
}

char	*check_var(char *line, t_vars *vars)
{
	char	*var_name;
	char	*var_value;
	char	*newline;

	newline = calloc(ft_strlen(line) + 1, sizeof(char));
	newline = ft_strcpy(newline, line);
	while (find_var_inline(newline))
	{
		var_name = save_varname(find_var_inline(newline) + 1);
		if (!ft_strcmp(var_name, "?"))
			var_value = ft_itoa(vars->last_output);
		else
			var_value = ft_getenv(vars->env, var_name);
		newline = add_varcontent(newline, var_name, var_value);
		free(var_value);
	}
	line = ft_strcpy(line, newline);
	free(newline);
	return (line);
}
