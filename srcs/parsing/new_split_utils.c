
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
	while (!ft_iswhitespace(line[i]) && line[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

int	len_single_quoted_word(char *line, int i)
{
	int	l;

	l = 0;
	i++;
	while (ft_isquote(line[i]) != 1)
	{
		i++;
		l++;
	}
	return (l);
}

int	len_double_quoted_word(char *line, int i)
{
	int	l;

	l = 0;
	i++;
	while (ft_isquote(line[i]) != 2)
	{
		i++;
		l++;
	}
	return (l);
}
