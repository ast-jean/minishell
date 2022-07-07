#include "../include/minishell.h"


void	quit_shell(t_vars *vars)
{
	(void)vars;
	//free() every token after being used
	
	exit(0);

}

void	executing_command(char *line, t_vars *vars)
{
	
	creating_tokens(line, vars);
	printf("Executing command\n");
}




int main(void)
{
	char *line;
	t_vars	vars;

	while (1)
	{
		line = readline("");
		//malloc char **line = parse_split
		executing_command(line, &vars);
		// printf( "%s\n", line);
		printf("Fault1?\n");
		debug_print_tokens(&vars);
	}

	return 0;
}
