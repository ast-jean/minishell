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

char	*newtoken_q(char *line, int i, char c)
{
	char	*str;
	int		len;
	int		x;

	x = 1;
	len = quote_len(line + i, c);
	printf("strlen: %d\n", len);
	str = malloc(sizeof(char) * (len + 1));
	str[0] = line[(i)++];
	while (--len)
		str[x++] = line[(i)++];
	str[x] = 0;
	// printf("str: %s\n", str);
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			ft_strjoin(str, newtoken_q(line, i, line[i]));
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		else if (line[i])
		{
			ft_strjoin(str, newtoken_s(line, i));
			while (line[i])
				i++;
		}
	}
	// printf("str: %s\n", str);
	return (str);
}

char	*newtoken_s(char *line, int i)
{
	char	*str;
	int		len;
	int		x;
	char	c;

	x = 0;
	c = 0;
	len = ft_strlen(line + (i));
	str = malloc(sizeof(char) * (len + 1));
	while (line[i])
		str[x++] = line[(i)++];
	str[x] = 0;
		while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			ft_strjoin(str, newtoken_q(line, i, line[i]));
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		else if (line[i])
		{
			ft_strjoin(str, newtoken_s(line, i));
			while (line[i])
				i++;
		}
	}
	// printf("str: %s\n", str);
	return (str);
}

char	*newtoken_d(char *line, char *delims, int i, int j)
{
	char	*str;
	int		len;
	int		x;

	x = 1;
	len = 0;
	while (!line[(i + len)] && delims[(j) + len] == delims[j])
		len++;
	printf("strlen: %d\n", len);
	str = malloc(sizeof(char) * (len + 1));
	str[0] = delims[j];
	i += (i) + len;
	while (--len)
		str[x++] = delims[(j)++];
	str[x] = 0;
	(j)++;
	// printf("str: %s\n", str);
	return (str);
}