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

	//Built-in nothing-------------
	if (ft_strlen(line) == 0)
	{
		printf("nothing\n");
		line = "";
		return ;
	}
	creating_tokens(line, vars);
	current = vars->token->first;
	//Built-in nothing-------------

	//Built-in exit-------------
	if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	//Built-in exit-------------



	//to be continued
}

int main(int argc, char **argv, char **env)
{
	char *line;
	t_vars	vars;

	line = NULL;
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


// int main(int argc, char **argv, char **env)
// {
// 	char *line;
// 	t_vars	vars;

// 	(void)argc;
// 	(void)argv;
// 	(void)env;
// 	line = "test";
// 		// init_shell(&vars);
// 		printf("line = >%s<\n", line);
// 		executing_command(line, &vars);
// 		debug_print_tokens(&vars);
// 		printf("The End\n");
// 	return 0;
// }