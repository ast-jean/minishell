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

int	is_builtin(t_token *current, t_vars *vars)
{
	//Built-in export-------------
	if(!ft_strcmp(current->cont, "export"))
		return (builtin_export(current, vars));
	// else if(!ft_strcmp(current->cont, "unset"))
	// 	builtin_unset(vars, current->next->cont);
	else if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	else if(!ft_strcmp(current->cont, "pwd"))
		return (builtin_pwd(vars));
	else if(!ft_strcmp(current->cont, "env"))
		return (builtin_env(vars));
	else if(!ft_strcmp(current->cont, "echo"))
		return (builtin_echo(vars));
	return (-1);
}

void	executing_command(char *line, t_vars *vars)
{
	t_token	*current;

	if (ft_strlen(line) == 0)
		return ;
	creating_tokens(line, vars);
	if(!check_heredocs(vars))
		return ;
	if (parsing_pipes(vars) == -1)
		return ;
	current = vars->token->first;
	while (vars->pipe_count--)
	{
		if (is_builtin(current, vars) == -1)
	}
	//MANAGE $VARS-------------
	//create struct of saved variables and add them if $VAR
	//-------------
	//Built-in export-------------
	if(!ft_strcmp(current->cont, "export"))
		builtin_export(current, vars);
	// else if(!ft_strcmp(current->cont, "unset"))
	// 	builtin_unset(vars, current->next->cont);
	else if(!ft_strcmp(current->cont, "exit"))
		quit_shell(vars);
	else if(!ft_strcmp(current->cont, "pwd"))
		builtin_pwd(vars);
	else if(!ft_strcmp(current->cont, "env"))
		builtin_env(vars);
	else if(!ft_strcmp(current->cont, "echo"))
		builtin_echo(vars);
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

void	remove_tmp_files(t_vars *vars)
{
	int i;
	char *filename;

	i = -1;
	while(++i < vars->heredoc_count)
	{	
		filename = ft_strjoin(".tmp/temp_heredoc", ft_itoa(i));
		unlink(filename);
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
	(void)argc; //use?
	vars.av = argv;
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
		// remove_tmp_files(&vars);
	}
	quit_shell(&vars);
	return 0;
}
