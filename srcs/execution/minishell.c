#include "../../include/minishell.h"

void init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	// vars->pwd = ft_calloc(ft_strlen(ft_arraysrch(env, "PWD")), sizeof(char));
	vars->pwd = ft_arraysrch(env, "PWD=") + 4;
	// vars->oldpwd = ft_calloc(ft_strlen(ft_arraysrch(env, "OLDPWD")), sizeof(char));
	vars->oldpwd = ft_arraysrch(env, "OLDPWD=") + 7;
	printf("*******************************\n");
	printf("*          MINISHELL          *\n");
	printf("*******************************\n");
}

void	executing_command(char *line, t_vars *vars)
{
	t_token	*current;
	if (ft_strlen(line) == 0)
		return ;
	creating_tokens(line, vars);
	current = vars->token->first;
	
	check_heredocs(vars); //(ast-jean) <<

	//MANAGE $VARS-------------
	//create struct of saved variables and add them if $VAR
	//-------------
	//Built-in export-------------
	if(!ft_strcmp(current->cont, "export"))
		ft_export(current, vars);
	else if(!ft_strcmp(current->cont, "unset"))
		ft_unset(vars, current->next->cont);
	else if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	else if(!ft_strcmp(current->cont, "pwd"))
		ft_pwd(vars);
	else if(!ft_strcmp(current->cont, "env"))
		ft_env(vars);
/*debug*/	// else if(!ft_strcmp(current->cont, "ls"))
	// 	executing_simple_cmds(vars, current);
	else if (!accessing(vars, current)) //si command est dans le path
	{
		executing_simple_cmds(vars, current);
	}
	else
	{
		printf("command not found '%s'\n", current->cont);
		return ;
	}
	// if(current)
	// 	free_tokens(vars);
/*debug*/printf("\033[43mcommand is '%s'\033[0m\n", current->cont);
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
		executing_command(line, &vars);
	}
	quit_shell(&vars);
	// unlink(".temp_heredoc0"); tried to delete temp file
	return 0;
}


// TESTS
