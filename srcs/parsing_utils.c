// #include "../include/minishell.h"
#include <stdbool.h>

bool	ft_iswhitespace(const int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v')
		return (true);
	return (false);
}

bool	ft_isquote(const int c)
{
	if (c == 34 || c == 39)
		return (true);
	return (false);
}

bool	ft_iseven(const int c)
{
	if ((c % 2) == 0)
		return (true);
	return (false);
}

bool	ft_isuneven(const int c)
{
	if ((c % 2) != 0)
		return (true);
	return (false);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

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
	while(!ft_iswhitespace(line[i]))
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
	while(!ft_isquote(line[i]))
	{
		i++;
		l++;
	}
	
	return (l);
}
