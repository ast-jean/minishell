#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	ft_isquote(const int c);
bool	ft_iswhitespace(const int c);
bool	ft_iseven(const int c);
bool	ft_isuneven(const int c);
int	how_many_quotes(char *str);
int	ft_isprint(int c);
int	len_of_this_word(char *line, int i);
int	len_of_this_quoted_word(char *line, int i);

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

char	*quoted_wrd_array(char *line, int *n)
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
	while (line[++(*n)] && !ft_isquote(line[*n]))
	{
		// printf("%c", line[n]);
		str[i] = line[*n];
		i++;
	}
	str[i] = '\0';
	// printf("\n");
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
		if (ft_isquote(line[i]))
			tab[x] = quoted_wrd_array(line, &i);
		else if (line[i])
			tab[x] = unquoted_wrd_array(line, &i);
		x++;
		while (line[i] && !ft_iswhitespace(line[i]))
			i++;
	}
	tab[x] = NULL;
	return (tab);
}

// --------Real-split----------------------------------------------------------
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
// ----------------------------------------------------------------------------

int	main(void)
{
	char *one_string = "'Hello' childen i \"wish you\" happy morning";
	char **tokens;
	char **true_str;
	tokens = new_split(one_string);

	printf("<%s> ", tokens[0]);
	printf("<%s> ", tokens[1]);
	printf("<%s> ", tokens[2]);
	printf("<%s> ", tokens[3]);
	printf("<%s> ", tokens[4]);
	printf("<%s> ", tokens[5]);
	printf("<%s> ", tokens[6]);
	printf("<%s>", tokens[7]);
	printf("\n\n");

	true_str = ft_split(one_string, ' ');
	printf("<%s> ", true_str[0]);
	printf("<%s> ", true_str[1]);
	printf("<%s> ", true_str[2]);
	printf("<%s> ", true_str[3]);
	printf("<%s> ", true_str[4]);
	printf("<%s> ", true_str[5]);
	printf("<%s> ", true_str[6]);
	printf("<%s>\n", true_str[7]);
}
