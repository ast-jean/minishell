// (xchouina)
#include "../../include/minishell.h"

void	finding_paths(t_vars *vars, char **env)
{
	int	i;

	i = 0;
	vars->path = NULL;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			vars->path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	// if (vars->path == NULL)
		// print_error(vars, 2);
	vars->env = ft_split(vars->path + 5, ':');
}

int	accessing(t_vars *vars, int n)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	vars->cmd_line = ft_split(vars->av[n], ' ');
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

	void	executing_simple_cmds(t_vars *vars, char **env)
{
	
	finding_paths(vars, env);
	accessing(vars, 0); // 0 is av[0]

	execve(vars->path, vars->cmd_line, NULL);
}
