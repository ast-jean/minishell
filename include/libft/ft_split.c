/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:55:01 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/18 11:06:09 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*mallocating_wrd_array(const char *s, char c)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != c)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		i;
	int		wc;

	i = 0;
	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	str_array = malloc(sizeof(char *) * (wc + 1));
	if (!str_array)
		return (NULL);
	while (wc--)
	{
		while (*s && *s == c) //skipping whitespaces
			s++;
		str_array[i] = mallocating_wrd_array(s, c);
		i++;
		while (*s && *s != c)
			s++;
	}
	str_array[i] = NULL;
	return (str_array);
}
