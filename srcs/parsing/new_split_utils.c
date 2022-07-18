
#include "../../include/minishell.h"

int	how_many_quotes(char *str)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (str[i] != '\0')
	{
		if (ft_isquote(str[i]) == true)
			g++;
		i++;
	}
	return (g);
}

int	len_of_this_word(char *line, int i)
{
	int	l;

	l = 0;
	while (!ft_iswhitespace(line[i]))
	{
		i++;
		l++;
	}
	return (l);
}

int	len_of_this_quoted_word(char *line, int i)
{
	int	l;

	l = 0;
	i++;
	while (!ft_isquote(line[i]))
	{
		i++;
		l++;
	}
	return (l);
}

int	nbr_of_words(char const *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isquote(s[i]))
		{
			i++;
			while (!ft_isquote(s[i]))
				i++;
			count++;
			i++;
		}
		while (s[i] && ft_iswhitespace(s[i]))
			i++;
		if (s[i] && !ft_iswhitespace(s[i]) && !ft_isquote(s[i]))
			count++;
		while (s[i] && !ft_iswhitespace(s[i]) && !ft_isquote(s[i]))
			i++;
	}
	return (count);
}
