/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marie-soleiljarry <marie-soleiljarry@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:11:14 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/29 11:08:11 by marie-solei      ###   ########.fr       */
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

char	**split_del(char *line, char *d_found, int len)
{
	char	**split;
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

char	*nullify_loop(char *line, int *i, char *d_found, char *delims)
{
	char	c;
	int		j;

	j = 0;
	if (line[*i] == 34 || line[*i] == 39)
	{
		c = line[(*i)++];
		while (line[*i] && line[*i] != c)
			(*i)++;
	}
	if (!line[*i])
	{
		free(d_found);
		return (NULL);
	}
	else if (ft_strchr(delims, line[*i]))
	{
		d_found[j++] = line[*i];
		line[*i] = '\0';
	}
	return (line);
}

char	**nullify_str(char *line, char *delims, int len, int count)
{
	char	*d_found;
	int		i;
	char	*res;

	i = -1;
	d_found = ft_calloc(sizeof(char) * (count + 1), count);
	while (++i < len)
		res = nullify_loop(line, &i, d_found, delims);
	if (res == NULL)
		return (NULL);
	return (split_del(line, d_found, len));
}

char	**tokenize(char *line)
{
	int	len;
	int	count;

	if (!line)
		return (NULL);
	count = cnt_delims(line, " <>|");
	len = ft_strlen(line);
	return (nullify_str(line, " <>|", len, count));
}
