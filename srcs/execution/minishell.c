#include "../../include/minishell.h"

void init_shell(t_vars *vars)
{
	(void)vars;
	printf("*******************************\n*          MINISHELL          *\n*******************************\n");
}

void free_tokens(t_vars *vars)
{
	t_token *temp;

	temp = vars->token->first;
	while (temp->next)
	{
		printf("token->%s\n", temp->cont);
		temp = temp->next;
		free((temp->prev));
	}
}

void	quit_shell(t_vars *vars)
{
	(void)vars;
	// free_tokens(vars);
	exit(0);
}


void	executing_command(char *line, t_vars *vars)
{
	t_token *current;

	//Built-in nothing-------------
	if (ft_strlen(line) == 0)
	{
		printf("nothing\n");
		return ;
	}
	creating_tokens(line, vars);
	current = vars->token->first;
	//Built-in nothing-------------

	//Built-in exit-------------
	if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	//Built-in exit-------------


	if(current)
		free_tokens(vars);
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
		// debug_print_tokens(&vars); //causes segfault if no tokens
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