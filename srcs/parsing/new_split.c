
#include "../../include/minishell.h"

char	*unquoted_wrd_array(char *s, int *n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = len_of_this_word(s, *n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[*n] && !ft_iswhitespace(s[*n]))
	{
		str[i] = s[*n];
		i++;
		(*n)++;
	}
	str[i] = '\0';
	return (str);
}

char	*double_quoted_wrd_array(char *line, int *n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!line)
		return (NULL);
	len = len_of_this_quoted_word(line, *n);
	printf("---> %d <---\n", len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (line[++(*n)] && ft_isquote(line[*n] != 2))
	{
		str[i] = line[*n];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*single_quoted_wrd_array(char *line, int *n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!line)
		return (NULL);
	len = len_of_this_quoted_word(line, *n);
	printf("---> %d <---\n", len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (line[++(*n)] && ft_isquote(line[*n] != 1))
	{
		str[i] = line[*n];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**new_split(char *line)
{
	char	**tab;
	int		x;
	int		i;
	int		wc;

	i = 0;
	x = 0;
	wc = nbr_of_words(line);
	printf("wc = %d\n", wc);
	tab = malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	while (wc--)
	{
		while (line[i] && ft_iswhitespace(line[i])) //skipping whitespaces
			i++;
		if (ft_isquote(line[i]) == 2)
			tab[x] = double_quoted_wrd_array(line, &i);
		else if (ft_isquote(line[i]) == 1)
			tab[x] = single_quoted_wrd_array(line, &i);
		else if (line[i])
			tab[x] = unquoted_wrd_array(line, &i);
		x++;
		while (line[i] && !ft_iswhitespace(line[i]))
			i++;
	}
	tab[x] = NULL;
	return (tab);
}
