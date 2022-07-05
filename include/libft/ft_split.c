/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:09:21 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 16:27:32 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:55:01 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/06 18:01:03 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

<<<<<<< HEAD
static int	count_words(const char *s, char c)
{
	int	count;
	int	boolean;

	count = 0;
	boolean = 0;
	while (*s)
	{
		if (*s != c && boolean == 0)
		{
			boolean = 1;
			count++;
		}
		else if (*s == c)
			boolean = 0;
		s++;
=======
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
>>>>>>> main
	}
	return (count);
}

<<<<<<< HEAD
static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**scan_list(char const *s, char c, char **strs)
{
	size_t	i;
	size_t	j;
	int		word_start;

	i = 0;
	j = 0;
	word_start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start >= 0)
		{
			strs[j] = fill_word(s, word_start, i);
			word_start = -1;
			j++;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
=======
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
>>>>>>> main
}

char	**ft_split(char const *s, char c)
{
<<<<<<< HEAD
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	strs = scan_list((const char *)s, c, strs);
	return (strs);
=======
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
		while (*s && *s == c)
			s++;
		str_array[i] = mallocating_wrd_array(s, c);
		i++;
		while (*s && *s != c)
			s++;
	}
	str_array[i] = NULL;
	return (str_array);
>>>>>>> main
}
