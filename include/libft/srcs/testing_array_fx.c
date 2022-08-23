#include "../include/libft.h"

int	main(void)
{
	char **tab;
	char **newt;
	tab = malloc(sizeof(char *) * 5);
	tab[0] = "Hello";
	tab[1] = "second";
	tab[2] = "third";
	tab[3] = "fourth";
	tab[4] = "fifth";
	ft_arrayprint(tab);
	printf("----\n");
	newt = ft_arrayrm(tab, "third");
	ft_arrayfree(tab);
	ft_arrayprint(tab);
		ft_arrayprint(tab);
}