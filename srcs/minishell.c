#include "../include/minishell.h"


void	executing_command(char *line)
{
	creating_token(line);

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
}

int main(void)
{
	char *line;

	while(1)
	{
		line = readline("");
		executing_command(line);
		printf( "%s\n", line);
	}
	return 0;
}
