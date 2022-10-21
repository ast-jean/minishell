#include "../../include/minishell.h"

// NOTE: CREATES PIPES


void	handler_exec(int sig)
{
	(void)sig;
}

int	close_fds(int fdi, int fdo, int to_return)
{
	if (fdi != 0)
		close(fdi);
	if (fdo != 1)
		close(fdo);
	return (to_return);
}
int	is_bi_nopipes(t_token *current, t_vars *vars, char **env)
{
	if (vars->pipe_count > 0)
	{
		if (current && (!ft_strcmp(remove_quotes(current->cont), "export")
				|| !ft_strcmp(remove_quotes(current->cont), "unset")
				|| !ft_strcmp(remove_quotes(current->cont), "cd")
				|| !ft_strcmp(remove_quotes(current->cont), "exit")))
				return (-2);
		return (-1);
	}
	if (current && !ft_strcmp(remove_quotes(current->cont), "export"))
		return (builtin_export(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "unset"))
		return (builtin_unset(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "cd"))
		return (builtin_cd(vars, env));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "exit"))
	{
		close_fds(vars->fdi, vars->fdo, 0);
		quit_shell(vars);
	}

	return (-1);
}


int	is_builtin(t_token *current, t_vars *vars)
{
	if (current && !ft_strcmp(remove_quotes(current->cont), "pwd"))
		return (builtin_pwd(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "env"))
		return (builtin_env(vars));
	else if (current && !ft_strcmp(remove_quotes(current->cont), "echo"))
		return (builtin_echo(current, vars));
	return (-1);
}

void	format_execve(t_vars *vars, t_token *token)
{
	t_token	*current;
	int		i;

	current = token;
	i = 0;
	vars->ac = 0;
	vars->av = NULL;
	while (current && current->group_num == token->group_num)
	{
		vars->ac++;
		current = current->next;
	}
	vars->av = malloc(sizeof(char *) * (vars->ac + 1));
	vars->av[i] = remove_quotes(token->cont);
	while (++i < vars->ac)
	{
		vars->av[i] = remove_quotes(token->next->cont);
		token = token->next;
	}
	vars->av[i] = NULL;
	execve(vars->path, vars->av, vars->env);
	exit(errno);
}

t_token	*skip_group(int group, t_vars *vars)
{
	t_token *current;

	current = vars->token->first;
	while (current && current->group_num <= group)
		current = current->next;
	return (current);
}

void	actually_forking(t_token *current, t_vars *vars, char **env)
{
	vars->pid[vars->pid_count] = fork();
	if (vars->pid[vars->pid_count++] == 0)
	{
		// signal(SIGINT, 	SIG_IGN);
		signal(SIGINT, 	handler_exec);
		signal(SIGQUIT, SIG_DFL);
		dup2(vars->fdi, 0);
		dup2(vars->fdo, 1);
		close_fds(vars->fdi, vars->fdo, 0);
		if (is_builtin(current, vars) == -1)
		{
			if (accessing(vars, current) == -1
				&& is_bi_nopipes(current, vars, env) == -1)
			{
				ft_putstr_fd(remove_quotes(current->cont), 2);
				ft_putstr_fd(": cmd not found\n", 2);
				exit(1);
			}
			else
				format_execve(vars, current);
		}
		exit(0);
	}
	else	
		signal(SIGINT, SIG_IGN);
}

int	finding_redirs(t_token *current, int fdi, t_vars *vars, char **env)
{
	int	pipefd[2];

	vars->fdi = fdi;
	if (current->group_num < (vars->pipe_count + 1) && vars->pipe_count > 0)
	{
		pipe(pipefd);
		vars->fdo = redirect_output(current, pipefd[1]);
	}
	else
		vars->fdo = redirect_output(current, 1);
	current = rm_redir(current, vars);
	if (vars->fdi == -1)
	{
		ft_putstr_fd(": no such file or directory\n", 2);
		write(pipefd[1], "", 0);
		return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
	}
	if (current && is_bi_nopipes(current, vars, env) >= 1)
		return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
	else
		actually_forking(current, vars, env);
	return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
}

void	fd_catch(t_vars *vars, t_token *current, char **env)
{
	int	fd;
	int	i;
	int	group;

	vars->pid_count = 0;
	// free2d(vars->path_array);
	finding_paths(vars);
	group = current->group_num;
	fd = finding_redirs(current, redirect_input(current, 0), vars, env);
	current = skip_group(group, vars);
	i = 0;
	while ((i++ < vars->pipe_count) && (vars->pid_count < 32766))
	{
		group = current->group_num;
		finding_paths(vars);
		fd = finding_redirs(current, redirect_input(current, fd), vars, env);
		current = skip_group(group, vars);
	}
	i = 0;
	while (i <= (vars->pid_count - 1))
	{
		printf("vars->last_output = %d\n",vars->last_output);
		printf("vars->status bef= %d\n",vars->status );
		printf("\033[31merrno bef= %d\033[0m\n",errno);
		printf("waitpid= %d\n", waitpid(vars->pid[i++], &vars->status, 0));
		printf("\033[31merrno= %d\033[0m\n",errno);
		printf("vars->status = %d\n",vars->status);
		if (get_error(vars->status))
		{
			vars->last_output = get_error(vars->status);
			printf("vars->last_output = %d\n",vars->last_output);
		}
		else if (errno)
			vars->last_output = errno;
		else
			vars->last_output = 0;
	}
	signal(SIGINT, handler);
	if (vars->pipe_count > 0 && fd > 2)
		close(fd);
		// free_tokens()
}

// some fds not getting closed for some reason