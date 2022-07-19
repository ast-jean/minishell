
#include "../../include/minishell.h"

int	nbr_of_words(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_iswhitespace(s[i]))
			i++;
		if (ft_isquote(s[i]) == 1)
		{
			i = nbr_of_letters(s, i, 1);
			count++;
		}
		else if (ft_isquote(s[i]) == 2)
		{
			i = nbr_of_letters(s, i, 2);
			count++;
		}
		if (s[i] != '\0' && !ft_iswhitespace(s[i]) && !ft_isquote(s[i]))
			count++;
		while (s[i] != '\0' && !ft_iswhitespace(s[i]) && !ft_isquote(s[i]))
			i++;
	}
	return (count);
}

int	nbr_of_letters(char *s, int i, int code)
{
	if (code == 1)
	{
		i++;
		while (ft_isquote(s[i]) != 1 && s[i])
			i++;
		i++;
	}
	else if (code == 2)
	{
		i++;
		while (ft_isquote(s[i]) != 2 && s[i])
			i++;
		i++;
	}
	return (i);
}
