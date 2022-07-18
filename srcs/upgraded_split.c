// #include "../include/minishell.h"
#include <stdbool.h>
#include <stdio.h>

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
}
