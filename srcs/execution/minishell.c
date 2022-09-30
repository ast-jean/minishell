#include "../../include/minishell.h"

t_hds *f_hds()
{
	static t_hds *a;
	static int	b;

	if(!b)
	{	
		a = malloc(sizeof(t_hds));
		b = 1;
		a->init = 1;
		a->end = 0;
		a->in_heredoc = 0;
	}
	return (a);
}

void	init_shell(t_vars *vars, char **env)
{
	vars->env = ft_arraycpy(env);
	vars->pwd = getenv("PWD");
	vars->oldpwd = getenv("OLDPWD");
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
	if (!creating_tokens(line, vars))
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

void	handler(int sig)
{
	// printf("special boi= %d\n", f_hds().pid);
	if (sig == SIGINT && !f_hds()->in_heredoc)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if(sig == SIGINT)
	{
		// printf("dsadsa\n");
		// f_hds()->in_heredoc = 0;
		f_hds()->end = 1;
		// rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
// close(0);
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
	char	*prompt;

	t_hds *a;
	a = f_hds(); //dont forget to free
	printf("in_heredoc = %d\n", a->in_heredoc);

	if (argc != 1)
		return (-1);
	(void)argv;
	prompt = "$>";
	vars.line = "";
	init_shell(&vars, env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		vars.line = readline(prompt);
		if (!vars.line)
		{
			quit_shell(&vars);
		}
		else if (ft_strcmp(vars.line, "") != 0)
			add_history(vars.line);
		executing_command(vars.line, &vars);
		remove_tmp_files(&vars);
	}
	quit_shell(&vars);
	return (0);
}
