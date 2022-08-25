// (xchouina)
#include "../../include/minishell.h"

void	finding_paths(t_token *vars)
{
	int		i;
	char	*path_str;
	char	**path_array;

	i = 0;
	path_str = 0;
	while (vars->env[i] != NULL)
	{
		if (ft_strnstr(vars->env[i], "PATH=", 5) != NULL)
			path_str = ft_strnstr(vars->env[i], "PATH=", 5);
		i++;
	}
	if (path_str = NULL);
		return (0);
	vars->path_array = ft_split(path_str, ':');
}

int	accessing(t_vars *vars, t_token *token)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	vars->path_array = ft_split(token->cont, ' ');
	cmd = ft_strjoin("/", vars->path_array[0]);
	i = 0;
	while (vars->env[i])
	{
		vars->path = ft_strjoin(vars->env[i], cmd);
		yes_or_no = access(vars->path, F_OK | X_OK);
		if (yes_or_no != -1)
		{
			free(cmd);
			return (1);
		}
		free(vars->path);
		i++;
	}
	free(cmd);
	// print_error(vars, 1);
	return (0);
}

void	executing_simple_cmds(t_vars *vars, t_token *token)
{
	finding_paths(vars, vars->env);
	accessing(vars, token);
	execve(vars->path, vars->path_array, NULL);
}
