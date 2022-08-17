#include "../../include/minishell.h"

void init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	vars->pwd = ft_calloc(ft_strlen(ft_arraysrch(env, "PWD")), sizeof(char));
	vars->pwd = ft_arraysrch(env, "PWD=") + 4;
	vars->oldpwd = ft_calloc(ft_strlen(ft_arraysrch(env, "OLDPWD")), sizeof(char));
	vars->oldpwd = ft_arraysrch(env, "OLDPWD=") + 7;
	printf("*******************************\n");
	printf("*          MINISHELL          *\n");
	printf("*******************************\n");
}

void free_tokens(t_vars *vars)
{
	t_token *temp;

	temp = vars->token->first;
	while (temp->next)
	{
		// printf("token->%s\n", temp->cont);
		temp = temp->next;
		free((temp->prev));
	}
}

void	quit_shell(t_vars *vars)
{
	(void)vars;
	// free_tokens(vars);
	//delete history

	exit(0);
}


void	executing_command(char *line, t_vars *vars, char **env)
{
	t_token *current;
	(void)env;
	if (ft_strlen(line) == 0)
		return ;
	creating_tokens(line, vars);
	current = vars->token->first;

	//MANAGE $VARS-------------
	//create struct of saved variables and add them if $VAR
	//-------------
	//Built-in export-------------
	if(!ft_strcmp(current->cont, "export")) //create struct of saved variables
		// ft_export(current->cont);			//ft_export will fetch variables names and put it in env
	//Built-in exit-------------
	if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	//-------------
	//Built-in pwd-------------
	if(!ft_strcmp(current->cont, "pwd"))
		ft_pwd(vars);
	//-------------
		//Built-in pwd-------------
	if(!ft_strcmp(current->cont, "env"))
		ft_env(vars);
	//-------------
	if(current)
		free_tokens(vars);
}

void	handler(int sig) 
{
	if (sig == SIGINT) //ctrl-C
	{
		printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
	}
}

int main(int argc, char **argv, char **env)
{
	char *line;
	t_vars	vars;	
	char *prompt;

	prompt= "$>";
	line = "";
	//---------
	(void)argc;
	(void)argv;
	//---------
	init_shell(&vars, env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline(prompt);
		if (!line) //ctrl-D
			quit_shell(&vars);
		else
     		add_history(line);
		executing_command(line, &vars, env); //maybe resplit between "|" "<, <<, >, >>"

		// debug_print_tokens(&vars); //causes segfault if no tokens
		printf("The End\n");
	}
	quit_shell(&vars);
	return 0;
}



// // TESTS
// int	main(void)
// {
// 	// int	i = 0;
// 	char	*str = "Hello how are you";
// 	char **tab;
// 	char **cpy_tab;

// 	tab = ft_split(str, ' ');
// 	printf("--------------------\n");
// 	printf("[len = %d]\n", ft_arraylen(tab));
// 	ft_arrayprint(tab);
// 	printf("--------------------\n");
// 	tab = ft_arrayadd(tab, "today");
// 	// printf("[len = %d]\n", ft_arraylen(tab));
// 	ft_arrayprint(tab);
// 	printf("--------------------\n");
// 	cpy_tab = ft_arraycpy(tab);
// 	ft_arrayprint(cpy_tab);
// }
