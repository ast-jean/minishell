#include "../../include/minishell.h"

// NOTE: CREATES PIPES
// TOKNOW: - if redirection to file before end of cmd line, redirection overwrites dup2 to pipe and pipe is empty. Next cmd will execute with empty imput.

//Execute has to call redirect_output and pipe anyways
//redirect output becomes stdout and overrides pipefd[1]);

t_token	*skip_group(t_token *current_token)
{
	int	t;

	t = current_token->group_num;
	while (current_token->next != NULL && current_token->group_num == t)
		current_token = current_token->next;
	return (current_token);
}


int	execute(t_token *current, int fdi, t_vars *vars)
{
	(void)vars;
	ft_putnbr_fd(fdi, 2);
	ft_putstr_fd(" = fd_recieved\n", 2);
	ft_putstr_fd(current->cont, 2);
	ft_putstr_fd(" = cmd to execute\n", 2);
	return (-2);
}

void	fd_catch(t_vars *vars, t_token *current)
{
	int	fd;

	fd = execute(current, redirect_input(current, 0), vars);
	current = skip_group(current);
	while (--vars->pipe_count)
	{
		fd = execute(current, redirect_input(current, fd), vars);
		current = skip_group(current);
	}
	execute(current, redirect_input(current, fd), vars);
}
