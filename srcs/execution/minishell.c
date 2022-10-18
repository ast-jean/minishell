#include "../../include/minishell.h"

void	init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	vars->oldpwd = getenv("OLDPWD");
	vars->path_array = NULL;
	vars->token = NULL;
	vars->last_output = 0;
	printf("*******************************\n");
	printf("*          MINISHELL          *\n");
	printf("*******************************\n");
}


// TOFIX : rename for check_token_type
void	parse_and_exec(char *line, t_vars *vars, char **env)
{
	if (ft_strlen(line) == 0)
		return ;
	if (!creating_tokens(line, vars))
	{
		
		if(!check_here(vars))
			return ;
		if (parsing_pipes(vars) == -1)
			return ;
		fd_catch(vars, vars->token->first, env);
	}
}

void	handler(int sig)
{
	int	pid;

	pid = getpid();
	printf("\npid = %d\n", pid);
	if (pid > 0)	
	{
		if (sig == SIGINT)
		{
			ft_putstr_fd("\n", 2);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else
	{
		if (sig == SIGINT)
		{
			ft_putstr_fd("----TEST----", 2);
		}
	}
}

void	remove_tmp_files(t_vars *vars)
{
	int		i;
	char	*filename;
	char	*num;

	i = -1;
	while(++i <= vars->heredoc_count)
	{	
		num = ft_itoa(i);
		filename = ft_strjoin(".tmp/temp_heredoc", num);
		unlink(filename);
		free(num);
		free(filename);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_vars	vars;	
	char	*line;
	char	*prompt;

	if (argc != 1)
		return (-1);
	(void)argv;
	prompt = "$>";
	line = NULL;
	init_shell(&vars, env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		// signal(SIGINT, handler);
		// signal(SIGQUIT, SIG_IGN);
		line = readline(prompt);
		if (!line)
			quit_shell(&vars);
		else if (ft_strcmp(line, "") != 0)
			add_history(line);
		parse_and_exec(line, &vars, env);
		remove_tmp_files(&vars);
	}
	quit_shell(&vars);
	return (0);
}
