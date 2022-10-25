/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:18:02 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/25 13:16:31 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quote_len(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (!str[i])
		return (-1);
	return (i + 1);
}

char	*newtoken_q(char *line, int *i, char c)
{
	char	*str;
	char	*str2;
	int		len;
	int		x;

	x = 1;
	len = quote_len(line + (*i), c);
	if (len == -1)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	str[0] = line[(*i)++];
	while (--len)
		str[x++] = line[(*i)++];
	str[x] = 0;
	str2 = str;
	while (line[*i])
	{
		if (line[*i] == 34 || line[*i] == 39)
		{
			str2 = ft_strjoinf2(str, newtoken_q(line, i, line[*i]));
			free(str);
		}
		else if (line[*i])
		{
			str2 = ft_strjoinf2(str, newtoken_s(line, i));
			free(str);
		}
	}
	return (str2);
}

char	*newtoken_s(char *line, int *i)
{
	char	*str;
	char	*str2;
	int		len;
	int		x;

	x = 0;
	len = ft_strlen(line + (*i));
	str = malloc(sizeof(char) * (len + 1));
	str2 = str;
	while (line[*i])
		str[x++] = line[(*i)++];
	str[x] = 0;
	while (line[*i])
	{
		if (line[*i] == 34 || line[*i] == 39)
		{
			str = ft_strjoinf2(str2, newtoken_q(line, i, line[*i]));
			free(str2);
		}
	}
	return (str);
}

char	*newtoken_d(char *line, char *delims, int i, int j)
{
	char	*str;
	int		len;
	int		x;

	x = 1;
	len = 0;
	while (!line[(i + len)] && delims[(j) + len] == delims[j])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[0] = delims[j];
	i += (i) + len;
	while (--len)
		str[x++] = delims[(j)++];
	str[x] = 0;
	(j)++;
	return (str);
}

void	increm(int *i, int *j)
{
	(*i)++;
	(*j)++;
}
