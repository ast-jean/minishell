#include "../../include/minishell.h"


// MAIN FOR TESTING
int	main(void)
{
	char *one_string = "'Hello\" childen i \"wish you\" happy morning";
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
