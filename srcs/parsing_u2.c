#include <stdio.h>
#include <stdbool.h>


char	**ft_split(char *line)
{
	int i;
	int x;
	int y;
	char **tab;

	i = 0;
	x = 0;
	tab = (char**)malloc(sizeof(**tab) * (nbr_of_words(line) + 1));
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]))
		{
			y = 0;
			tab[x] = (char*)malloc(sizeof(char) * len_of_this_word(line, i));
			while (line[i] > 32)
			{
				tab[x][y] = line[i];
				i++;
				y++;
			}
			tab[x][y] = '\0';
			x++;
		}
		else
			i++;
	}
	tab[x] = 0;
	return (tab);
}
