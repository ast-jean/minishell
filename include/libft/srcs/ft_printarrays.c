
#include "../include/libft.h"

char	**ft_split(char const *s, char c);
void	ft_printarray(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s", tab[i++]);
	}
}

int main (void)
{
	char *str = "Hello beautiful world how are you today";
	char **tab = ft_split(str, ' ');
	ft_printarray(tab);
}





// print_array
// 