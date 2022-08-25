#include "../../include/minishell.h"

int	cnt_delims(char *line, char *delims)
{
	int		i;
	int 	count;
	char	c;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		else if (ft_strchr(delims, line[i]))
			count++;
		i++;
	}
	return (count);
}



char	**split_del(char *line, char *d_found, int len, int count)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = NULL;
	while (i < len && j < count)
	{
		if (line[i] == 34 || line[i] == 39)
			split = ft_arrayadd(split, newtoken_q(line, &i, line[i]));
		else if (line[i])
			split = ft_arrayadd(split, newtoken_s(line, &i));
		// else if (d_found[j] && d_found[j] != ' ')
		// 	split = ft_arrayadd(split, newtoken_d())
	}
	return (split);
}

char	**nullify_str(char *line, char *delims, int len, int count)
{
	char	*d_found;
	char	c;
	int		i;
	int		j;

	i = -1;
	j = 0;
	d_found = ft_calloc(sizeof(char) * (count + 1), count);
	while(++i < len)
	{
		if (line[i] == 34 || line[i] == 39)
		{
			c = line[i++];
			while (line[i] && line[i] != c)
				i++;
		}
		else if (ft_strchr(delims, line[i]))
		{
			d_found[j] = line[i];
			line[i] = '\0';
			j++;
		}
	}
	return (split_del(line, d_found, len, count));
}

char	**tokenize(char *line)
{
	int	i;
	int	len;
	int	count;
	
	i = 0;
	count = cnt_delims(line, " <>|");
	len = ft_strlen(line);
	return(nullify_str(line, " <>|", len, count));
}

int main(void)
{
	char str[] = "test is< \"what this is\"";
	tokenize(str);
}

//type 0-line 1-delims
// char	*newtoken(char *line, char *d_found int *i, int *j, int type)
// {
// 	char	*str;
// 	int		len;
// 	int		k;
// 	char	c;

// 	k = 0;
// 	len = 0;
// 	if (type == 0)
// 	{
// 		len = ft_strlen(line + (*i));
// 		printf("strlen: %d\n", len);
// 		str = malloc(sizeof(char) * (len + 1));
// 		while (line[*i])
// 			str[k++] = line[(*i)++];
// 		str[k] = '\0';
// 	}
// 	else if (type == 1)
// 	{
// 		c = line[*i];
// 		while (line[(*i) + len] == c)
// 			len++;
// 		printf("strlen: %d\n", len);
// 		str = malloc(sizeof(char) * (len + 1));
// 		while (line[*i])
// 			str[k++] = line[(*i)++];
// 		str[k] = '\0';
// 	}
// 	printf("str: %s\n", str);
// 	return(str);
// }