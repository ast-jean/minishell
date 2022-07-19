#include "../../include/minishell.h"


// MAIN FOR TESTING
int	main(void)
{

	int i = 0;
	char **tokens;
	char *one_string = 
		"\"Hello    children\"   i 'wish you' happy 'morning'";
		// "Hello      'children i' wish you happy morning";
		// "Hello      'children i' wish you 'happy' morning";
		// "Hello children i wish you happy morning";
	
	tokens = new_split(one_string);
	
	while (tokens[i])
		printf("<%s> ", tokens[i++]);
	printf("\n");

}
