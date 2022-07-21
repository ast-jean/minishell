#include "../../include/minishell.h"

void init_shell(t_vars *vars)
{

	(void)vars;

	printf("*******************************\n*          MINISHELL          *\n*******************************\n");

}

void	quit_shell(t_vars *vars)
{
	(void)vars;
	//free() every token after being used
	
	exit(0);

}

void	executing_command(char *line, t_vars *vars)
{
	t_token *current;
	creating_tokens(line, vars);
	//-------------------------------
	//Executing commands
	//-------------------------------
	current = vars->token->first;
	if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);



	//to be continued
}

int main(int argc, char **argv, char **env)
{
	char *line;
	t_vars	vars;

	(void)argc;
	(void)argv;
	(void)env;
	init_shell(&vars);
	while (1)
	{
		line = readline("$>");
		executing_command(line, &vars);
		debug_print_tokens(&vars);
		printf("The End\n");
	}

	return 0;
}
