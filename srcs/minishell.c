#include "../include/minishell.h"


void	quit_shell(t_vars *vars)
{
	(void)vars;
	//free() every token after being used
	
	exit(0);

}

void	executing_command(char *line)
{
	(void)line;
//	creating_token(line);
	printf("Executing command\n");
}

void *access_ptr(t_vars *vars, int i)
{
	int count;

	count = 0;
	vars->token = vars->token->first;
	while (count <= i)
	{
		vars->token = vars->token->next;
	}
	return (vars->token);
}

int main(void)
{
	char *line;
	t_vars	vars;

	(void)vars;


	while(1)
	{
		line = readline("");
		//malloc char **line = parse_split
		executing_command(line);
		printf( "%s\n", line);
	}
	return 0;
}
