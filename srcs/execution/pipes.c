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
				exit(0);
			}
		}
		format_execve(vars, current);
	}
}

int	forking(t_token *current, int fdi, t_vars *vars, char **env)
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
		actually_forking(current, vars, env);
	return (close_fds(vars->fdi, vars->fdo, pipefd[0]));
}

void	fd_catch(t_vars *vars, t_token *current, char **env)
{
	int	fd;
	int	i;

	vars->pid_count = 0;
	finding_paths(vars);
	fd = forking(current, redirect_input(current, 0), vars, env);
	current = skip_group(current);
	i = 0;
	while ((i++ < vars->pipe_count) && (vars->pid_count < 32766))
	{
		finding_paths(vars);
		fd = forking(current, redirect_input(current, fd), vars, env);
		current = skip_group(current);
	}
	i = 0;
	while (i <= (vars->pid_count - 1))
		waitpid(vars->pid[i++], &vars->status, 0);
}
