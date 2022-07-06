// #include "../include/minishell.h"
#include <stdbool.h>
#include <stdio.h>

// char	*mallocating_wrd_array(const char *s, char c)
// {
// 	char	*str;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[len] && s[len] != c)
// 		len++;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s[i] && s[i] != c)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_array;
// 	int		i;
// 	int		wc;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	wc = ft_wordcount(s, c);
// 	str_array = malloc(sizeof(char *) * (wc + 1));
// 	if (!str_array)
// 		return (NULL);
// 	while (wc--)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		str_array[i] = mallocating_wrd_array(s, c);
// 		i++;
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	str_array[i] = NULL;
// 	return (str_array);
// }



// Modifie wordcount
// 


void	splitting_tokens(char *line)
{
	int		i;
	int		x;
	int		y;
	char	**tab;

	i = 0;
	if (!line)
		return (error);
	if (ft_iseven(how_many_quotes(line)) == false)
		return (error);
	new_split;

// 
	tab = malloc(sizeof(char *) * (ft_wordcount(line) + 1));
	if (!tab)
		return (NULL);
	while (is_whitespace(line[i]) == true)
		i++;
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) == 1)
		{

		}
		else
			i++;
	}

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


// int	main(void)
// {
// 	// char *str = "'Hello' my cat   is 'sick''to the   bones'";
// 	char *str1 = "  r   'Hello'  ";
// 	printf("\n");
// 	printf("--> %d\n", ft_wordcount(str1));
// }