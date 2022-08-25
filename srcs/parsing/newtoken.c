#include "../../include/minishell.h"

int	quote_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == c)
			break;
	}
	return (i + 1);
}

char	*newtoken_q(char *line, int *i, char c)
{
	char	*str;
	int		len;
	int		x;

	x = 1;
	len = quote_len(line + (*i), c);
	printf("strlen: %d\n", len);
	str = malloc(sizeof(char) * (len + 1));
	str[0] = line[(*i)++];
	while (--len)
		str[x++] = line[(*i)++];
	str[x] = 0;
	printf("str: %s\n", str);
	return (str);
}

char	*newtoken_s(char *line, int *i)
{
	char	*str;
	int		len;
	int		x;

	x = 0;
	len = ft_strlen(line + (*i));
	str = malloc(sizeof(char) * (len + 1));
	while (line[*i])
		str[x++] = line[(*i)++];
	str[x] = 0;
	printf("str: %s\n", str);
	return (str);
}

// char	*newtoken_d()
// {
// 	char	*str;
// 	int		len;
// 	int		x;

// 	x = 0;
// 	len = 
// 	str = malloc(sizeof(char) * (len + 1));
// }