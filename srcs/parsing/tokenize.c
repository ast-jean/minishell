/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:11:14 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/03 11:11:59 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cnt_delims(char *line, char *delims)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		else if (ft_strchr(delims, line[i]))
			count++;
		i++;
	}
	return (count);
}

char	**split_del(char **split, char *line, char *d_found, int len)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	split = NULL;
	while (i < len)
	{
		if (line[i] == 34 || line[i] == 39)
			split = ft_arrayadd(split, newtoken_q(line, &i, line[i]));
		else if (line[i])
			split = ft_arrayadd(split, newtoken_s(line, &i));
		else if (!line[i] && d_found[j] && d_found[j] != ' ')
		{
			split = ft_arrayadd(split, newtoken_d(line, d_found, i, j));
			c = d_found[j];
			while (d_found[j] && !line[i] && d_found[j] == c)
				increm(&i, &j);
		}
		else
			increm(&i, &j);
	}
	free(d_found);
	return (split);
}

char	**nullify_str(t_norm *norm)
{
	norm->i = -1;
	norm->j = 0;
	norm->split = NULL;
	norm->d_found = ft_calloc(sizeof(char) * (norm->count + 1), norm->count);
	while (++(norm->i) < norm->len)
	{
		if (norm->line[norm->i] == 34 || norm->line[norm->i] == 39)
		{
			norm->c = norm->line[(norm->i)++];
			while (norm->line[norm->i] && norm->line[norm->i] != norm->c)
				(norm->i)++;
		}
		if (!(norm->line[norm->i]))
		{
			free(norm->d_found);
			return (NULL);
		}
		else if (ft_strchr(norm->delims, norm->line[norm->i]))
		{
			norm->d_found[(norm->j)++] = norm->line[norm->i];
			norm->line[norm->i] = '\0';
		}
	}
	return (split_del(norm->split, norm->line, norm->d_found, norm->len));
}

char	**tokenize(char *line)
{
	t_norm	norm;

	norm.line = line;
	if (!(norm.line))
		return (NULL);
	norm.delims = " <>|";
	norm.count = cnt_delims(norm.line, norm.delims);
	norm.len = ft_strlen(norm.line);
	return (nullify_str(&norm));
}
