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
	int	pipefd[2];
	int	fdo;

	if (current->group_num != (vars->pipe_count + 1))
	{
		pipe(pipefd);
		fdo = redirect_output(current, pipefd[1]);
	}
	else
		fdo = redirect_output(current, 1);
	if (fdi != -1)
	{
		vars->pid[vars->pid_count] = fork();
		if (vars->pid[vars->pid_count] == 0)
		{
			dup2(fdi, 0);
			close(fdi);
			dup2(fdo, 1);
			close(fdo);
			// access_cmd(current, vars);
		}
		close(fdi);
	}
	close(fdo);
	return (pipefd[0]);
}

void	fd_catch(t_vars *vars, t_token *current)
{
	int	fd;
	vars->pid_count = 0;

	fd = execute(current, redirect_input(current, 0), vars);
	current = skip_group(current);
	// dprintf(1, "here\n");
	while ((--(vars->pipe_count) > 0) && (++(vars->pid_count) < 32766)) // max pid 32768
	{
		fd = execute(current, redirect_input(current, fd), vars);
		current = skip_group(current);
	}
	// execute(current, redirect_input(current, fd), vars);

}
