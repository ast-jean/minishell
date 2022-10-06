// (xchouina)
#include "../../include/minishell.h"

void	finding_paths(t_vars *vars)
{
	int		i;
	char	*path_str;

	i = 0;
	path_str = 0;
	while (vars->env[i] != NULL)
	{
		if (ft_strnstr(vars->env[i], "PATH=", 5) != NULL)
			path_str = ft_strnstr(vars->env[i], "PATH=", 5);
		i++;
	}
	if (path_str == NULL)
		return ;
	if (vars->path_array != NULL)
		free2d(vars->path_array);
	vars->path_array = ft_split(path_str, ':');
}

int	accessing(t_vars *vars, t_token *token)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	if (!token)
		return (-1);
	if (access(remove_quotes(token->cont), F_OK | X_OK) == 0)
	{
		vars->path = remove_quotes(token->cont);
		return (0);
	}
	cmd = ft_strjoin("/", remove_quotes(token->cont));
	i = 0;
	while (vars->path_array[i] != NULL)
	{
		vars->path = ft_strjoin(vars->path_array[i], cmd);
		yes_or_no = access(vars->path, F_OK | X_OK);
		if (yes_or_no == 0)
		{
			free(cmd);
			return (0);
		}
		free(vars->path);
		i++;
	}
	free(cmd);
	return (-1);
}

void	executing_simple_cmds(t_vars *vars, t_token *token)
{
	finding_paths(vars);
	accessing(vars, token);
	// execve(vars->path, CMD+FLAGS, NULL); // send env instead of NULL
}
