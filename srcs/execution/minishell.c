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

void	executing_command(char *line, t_vars *vars, char **env)
{
	t_token	*current;
	if (ft_strlen(line) == 0)
		return ;
	creating_tokens(line, vars);
	current = vars->token->first;

	//MANAGE $VARS-------------
	//create struct of saved variables and add them if $VAR
	//-------------
	//Built-in export-------------
	if(!ft_strcmp(current->cont, "export"))
		ft_export(current->cont,current->next->cont, vars->env, vars);
	if(!ft_strcmp(current->cont, "unset"))
		ft_unset(vars, current->next->cont);
	else if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	else if(!ft_strcmp(current->cont, "pwd"))
		ft_pwd(vars);
	else if(!ft_strcmp(current->cont, "env"))
		ft_env(vars);
	else if (!ft_strcmp(current->type, "cmd"))
		executing_simple_cmds(vars, current, env);
	else
		printf("command not found '%s'\n", current->cont);
	if(current)
		free_tokens(vars);
	rintf("command is '%s'\n", current->cont);
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

	}
	quit_shell(&vars);
	return 0;
}


// TESTS
