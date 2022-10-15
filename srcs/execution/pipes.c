#include "../../include/minishell.h"

// NOTE: CREATES PIPES

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
	char	*temp;

	temp = remove_quotes(current->cont);
	if (vars->pipe_count > 0)
	{
		if (current && (!ft_strcmp(temp, "export")
				|| !ft_strcmp(temp, "unset")
				|| !ft_strcmp(temp, "cd")
				|| !ft_strcmp(temp, "exit")))
			{
				// free(temp);
				return (-2);
			}
		// free(temp);
		return (-1);
	}
	if (current && !ft_strcmp(temp, "export"))
	{
		// free(temp);
		return (builtin_export(vars));
	}
	else if (current && !ft_strcmp(temp, "unset"))
	{
		// free(temp);
		return (builtin_unset(vars));
	}
	else if (current && !ft_strcmp(temp, "cd"))
	{
		// free(temp);
		return (builtin_cd(vars, env));
	}
	else if (current && !ft_strcmp(temp, "exit"))
	{
		// free(temp);

		ft_putstr_fd("exit\n", 2);
		close_fds(vars->fdi, vars->fdo, 0);
		quit_shell(vars);
	}
		// free(temp);

	return (-1);
}

int	is_builtin(t_token *current, t_vars *vars)
{
	char	*temp;

	temp = remove_quotes(current->cont);
	if (current && !ft_strcmp(temp, "pwd"))
	{
		// free(temp);
		return (builtin_pwd(vars));
	}
	else if (current && !ft_strcmp(temp, "env"))
	{
		// free(temp);
		return (builtin_env(vars));
	}
	else if (current && !ft_strcmp(temp, "echo"))
	{
		// free(temp);
		return (builtin_echo(current, vars));
	}
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
printf("errno right after execve= >%d<\n", errno);
	// exit(0);
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
				vars->last_output = 1;
				printf("output CHILD= >%d<\n", vars->last_output);
				exit(EXIT_FAILURE);
			}
			else if (is_bi_nopipes(current, vars, env) == -1)
				format_execve(vars, current);
		}
		exit(0);
	}
	waitpid(vars->pid[vars->pid_count], &vars->status, 0);
					printf("output PARENT= >%d<\n", vars->last_output);
}

int	finding_redirs(t_token *current, int fdi, t_vars *vars, char **env)
{
	int	pipefd[2];

	vars->fdi = fdi;
	if (current->group_num < (vars->pipe_count + 1))
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
	if (current && !is_bi_nopipes(current, vars, env))
		return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
	else
	{
		actually_forking(current, vars, env);
		printf("errno execvedsa= >%d<\n", errno);

	}
	printf("errno = >%d<\n", errno);
	return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
}

//when no_pipes executes, execve still does its thing!!!
void	fd_catch(t_vars *vars, t_token *current, char **env)
{
	int	fd;
	int	i;
	int	group;

	vars->pid_count = 0;
	finding_paths(vars);
	group = current->group_num;
	fd = finding_redirs(current, redirect_input(current, 0), vars, env);
	current = skip_group(group, vars);
	i = 0;
	while ((i++ < vars->pipe_count) && (vars->pid_count < 32766))
	{
		ft_putstr_fd("herreeee\n", 2);
		group = current->group_num;
		finding_paths(vars);
		fd = finding_redirs(current, redirect_input(current, fd), vars, env);
		current = skip_group(group, vars);
	}
	i = 0;
		printf("output= >%d<\n", vars->last_output);

	while (i <= (vars->pid_count - 1))
	{
		waitpid(vars->pid[i++], &vars->status, 0);
		printf("output WOWOWOWOW= >%d<\n", vars->last_output);
		printf("errno WOWOWOWOW= >%d<\n", errno);

	}
	
	// close(fd);
	// free_tokens()
}
