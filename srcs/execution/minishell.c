#include "../../include/minishell.h"

void	init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	vars->pwd = ft_arraysrch(env, "PWD=") + 4; // TOFIX  use function find_variables(env, "PWD=")
	// vars->oldpwd = ft_calloc(ft_strlen(ft_arraysrch(env, "OLDPWD")), sizeof(char));
	vars->oldpwd = ft_arraysrch(env, "OLDPWD=") + 7; // TOFIX  use function find_variables(env, "OLDPWD=")
	printf("*******************************\n");
	printf("*          MINISHELL          *\n");
	printf("*******************************\n");
}

// TOFIX : rename for check_token_type
void	executing_command(char *line, t_vars *vars)
{
	t_token	*current;

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
}

//sometimes prompt is printed twice after CTRL-C
void	handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	remove_tmp_files(t_vars *vars)
{
	int		i;
	char	*filename;

	i = -1;
	while(++i <= vars->heredoc_count)
	{	
		filename = ft_strjoin(".tmp/temp_heredoc", ft_itoa(i));
		unlink(filename);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_vars	vars;	
	char	*prompt;

	if (argc != 1)
		return (-1);
	(void)argv;
	prompt = "$>";
	line = "";
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
	return (0);
}
