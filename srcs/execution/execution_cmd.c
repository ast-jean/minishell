// (xchouina)
#include "../../include/minishell.h"

char	**finding_paths(t_token *vars)
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
	path_array = ft_split(path_str, ':');
	return (path_array);
}

int	accessing(t_vars *vars, t_token *token)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	vars->cmd_line = ft_split(token->cont, ' ');
	cmd = ft_strjoin("/", vars->cmd_line[0]);
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

void	executing_simple_cmds(t_vars *vars, t_token *token, char **env)
{
	finding_paths(vars, env);
	accessing(vars, token);
	execve(vars->path, vars->cmd_line, NULL);
}
