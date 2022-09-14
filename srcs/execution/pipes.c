#include "../../include/minishell.h"

// NOTE: CREATES PIPES
// TOKNOW: - if redirection to file before end of cmd line, redirection overwrites dup2 to pipe and pipe is empty. Next cmd will forking with empty imput.

//forking has to call redirect_output and pipe anyways
//redirect output becomes stdout and overrides pipefd[1]);

int	is_builtin(t_token *current, t_vars *vars)
{
	if (current && !ft_strcmp(current->cont, "export"))
		return (builtin_export(current, vars));
	else if (current && !ft_strcmp(current->cont, "pwd"))
		return (builtin_pwd(vars));
	else if (current && !ft_strcmp(current->cont, "env"))
		return (builtin_env(vars));
	else if (current && !ft_strcmp(current->cont, "echo"))
		return (builtin_echo(vars));
	// else if(!ft_strcmp(current->cont, "unset"))
	// 	builtin_unset(vars, current->next->cont);
	return (-1);
}

void	format_execve(t_vars *vars, t_token *token)
{
	t_token *current;
	int	i;

	current = token;
	i = 0;
	vars->ac = 0;
	vars->av = NULL;
	while (current && current->group_num == token->group_num)
	{
		vars->ac++;
		current = current->next;
	}
	vars->av = malloc(sizeof(char*) * (vars->ac + 1));
	vars->av[i] = token->cont;
	while (++i < vars->ac)
	{
		vars->av[i] = token->next->cont;
		token = token->next;
	}
	vars->av[i] = NULL;
	// printf("%s\n", vars->path);
	execve(vars->path, vars->av, vars->env);
	exit(0);
}

t_token	*skip_group(t_token *current_token)
{
	int	t;

	t = current_token->group_num;
	while (current_token->next != NULL && current_token->group_num == t)
		current_token = current_token->next;
	return (current_token);
}


int	forking(t_token *current, int fdi, t_vars *vars)
{
	int	pipefd[2];
	int	fdo;

	// printf("current : %s\n", current->cont);
	if(current && !ft_strcmp(current->cont, "exit"))
	{
		if (fdi != 0)
			close(fdi);
		quit_shell(vars);
	}
	if (current->group_num < (vars->pipe_count + 1))
	{
		pipe(pipefd);
		fdo = redirect_output(current, pipefd[1]);
	}
	else
		fdo = redirect_output(current, 1);
	current = rm_redir(current, vars);
	// printf("current : %s\n", current->cont);
	if (fdi == -1)
	{
		ft_putstr_fd("no such file or directory\n", 2);
		write(pipefd[1], "", 0);
		if (fdi != 0)
			close(fdi);
		if (fdo != 1)
			close(fdo);
		// close(pipefd[0]);
		return (pipefd[0]);
	}
	/*else if (fdi != -1 && !accessing(vars, current))
	{*/
		// printf("fdi: %d\nfdo: %d\n", fdi, fdo);
		vars->pid[vars->pid_count] = fork();
		if (vars->pid[vars->pid_count++] == 0)
		{
		// debug_print_tokens(vars);
			dup2(fdi, 0);
			if (fdi != 0)
				close(fdi);
			dup2(fdo, 1);
			if (fdo != 1)
				close(fdo);
			if (accessing(vars, current) == -1)
			{
				if (is_builtin(current, vars) == -1)
				{
					// printf("current : %s\n", current->cont);
					ft_putstr_fd(current->cont, 2);
					ft_putstr_fd(": cmd not found\n", 2);
					exit(0);
				}
			}
			format_execve(vars, current);
			exit(0);
		}
		if (fdi != 0)
			close(fdi);
		if (fdo != 1)
			close(fdo);
	// }
	return (pipefd[0]);
}

void	fd_catch(t_vars *vars, t_token *current)
{
	int	fd;
	int	i;
	vars->pid_count = 0;

	finding_paths(vars);
	fd = forking(current, redirect_input(current, 0), vars);
	current = skip_group(current);
	i = 0;
	while ((i++ < (vars->pipe_count)) && ((vars->pid_count) < 32766))
	{
		fd = forking(current, redirect_input(current, fd), vars);
		current = skip_group(current);
	}
	i = 0;
	while (i <= vars->pid_count)
		waitpid(vars->pid[i++], &vars->status, 0);
}
