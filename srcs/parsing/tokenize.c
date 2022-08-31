/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:17:56 by mjarry            #+#    #+#             */
/*   Updated: 2022/08/31 12:16:03 by mjarry           ###   ########.fr       */
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
	return (split);
}

char	**nullify_str(char *line, char *delims, int len, int count)
{
	char	*d_found;
	char	c;
	int		i;
	int		j;

	i = -1;
	j = 0;
	d_found = ft_calloc(sizeof(char) * (count + 1), count);
	while (++i < len)
	{
		if (line[i] == 34 || line[i] == 39)
		{
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		if (!line[i])
			return (NULL);
		else if (ft_strchr(delims, line[i]))
		{
			d_found[j++] = line[i];
			line[i] = '\0';
		}
	}
	return (split_del(line, d_found, len));
}

char	**tokenize(char *line)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	count = cnt_delims(line, " <>|");
	len = ft_strlen(line);
	return (nullify_str(line, " <>|", len, count));
}
