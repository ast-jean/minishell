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
	if(current && !ft_strcmp(current->cont, "export"))
		return (builtin_export(current, vars));
	// else if(!ft_strcmp(current->cont, "unset"))
	// 	builtin_unset(vars, current->next->cont);
	// else if(current && !ft_strcmp(current->cont, "exit"))
	// 	quit_shell(vars);
	else if(current && !ft_strcmp(current->cont, "pwd"))
		return (builtin_pwd(vars));
	else if(current && !ft_strcmp(current->cont, "env"))
		return (builtin_env(vars));
	else if(current && !ft_strcmp(current->cont, "echo"))
		return (builtin_echo(vars));
	return (-1);
}

void	cmd_not_found(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
}

// void	forking(t_vars *vars, t_token *current)
// {
// 	int	pid1;
// 	int	pid2;
// 	int	temp;

// 	finding_paths(vars);
// 	if ((vars->fdi != -1) && (accessing(vars, current) == 1)) // For 1st cmd
// 	{
// 		pid1 = fork();
// 		if (pid1 == 0)
// 		{ //could be a fx
// 			close; //	(pipefd[0]);
// 			dup2; //	(pipefd[1], 1);
// 			close; //	(pipefd[1]);
// 			dup2; //	(fdi, 0);
// 			close; //	(fdi);
// 			execve;
// 		}
// 		waitpid(pid1, &temp, 0);
// 		// TODO: fx to free	
// 	}
// 	if (accessing(vars, ???) == 1)
// 	{
// 		pid2 = fork();
// 		if (pid2 == 0)
// 		{ //could be a fx
// 			close; //	(pipefd[1]);
// 			dup2; //	(pipefd[0], 0);
// 			close; //	(pipefd[0]);
// 			dup2; //	(fdo, 1);
// 			close; //	(fdo);
// 			execve;
// 		}
// 		// TODO: fx to free	 
// 	}
// }

// TOFIX : rename for check_token_type
void	executing_command(char *line, t_vars *vars)
{
	t_token	*current;
	// int		i;
	// int		fd_default;

	if (ft_strlen(line) == 0)
		return ;
	creating_tokens(line, vars);
	
	if (vars->token != NULL)
	{
		if(!check_here(vars))
			return ;
// printf("---after checks---\n");
// /*debug*/debug_print_tokens(vars);
		if (parsing_pipes(vars) == -1)
			return ;
		current = vars->token->first;
		fd_catch(vars, current);
	}
	// debug_print_tokens(vars);
	// i = 0;
	// fd_default = 0;
	// while (++i <= current->group_num)
	// {
	// 	if (i != 1)
	// 		fd_default= vars->pipefd[1];
	// 	if (vars->fdi != fd_default)
	// 		close(vars->fdi);
	// 	vars->fdi = redirect_input(current, fd_default);
	// 	printf("fdi : %d\n", vars->fdi);
	// 	// current = remove_token(current);
	// 	// current->next = remove_token(current->next); <- makes me segfault
	// 	if (is_builtin(current, vars) == -1)
	// 	{
	// 		forking(vars, current);
	// 		// if (!accessing(vars, current)) //si command est dans le path
	// 		// 	format_execve(vars, current); //will format so execve receives right content
	// 		// else
	// 		return (cmd_not_found(current->cont));
	// 	}
	// 	else 
	// 	{
	// 		while (i == current->group_num)
	// 			current = current->next;
	// 	}
	// }
	//MANAGE $VARS-------------
	//create struct of saved variables and add them if $VAR
	//-------------
/*debug*/	// else if(!ft_strcmp(current->cont, "ls"))
	// 	executing_simple_cmds(vars, current);
	// if(current)
	// 	free_tokens(vars);
// /*debug*/printf("\033[43mcommand is '%s'\033[0m\n", current->cont);
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
	while(++i <= vars->heredoc_count)
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
		if (!line)
			quit_shell(&vars);
		else
     		add_history(line);
		executing_command(line, &vars);
		remove_tmp_files(&vars);
	}
	quit_shell(&vars);
	return 0;
}
