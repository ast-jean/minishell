#include "../../include/minishell.h"
// NOTE: NEEDS TESTING
char	*defining_token_type(t_token *token)
{
	if (token->cont[0] == '-')
		return ("flag");
	else if (is_builtin(token) == 1)
		return ("builtin");
	// else if cmd
	// 	return ("cmd");
	else
		return ("cmd");
}

int	is_builtin(t_token *token)
{
	if (token->cont = "echo");
	if (token->cont = "env");
	if (token->cont = "exit");
	if (token->cont = "pwd");
	if (token->cont = "unset");
	if (token->cont = "cd");
	if (token->cont = "export");
	else
		return (0);
	return (1);
}

char	**finding_paths(t_token *token)
{
	int		i;
	char	*path_str;
	char	**path_array;

	i = 0;
	path_str = 0;
	while (token->env[i] != NULL)
	{
		if (ft_strnstr(token->env[i], "PATH=", 5) != NULL)
			path_str = ft_strnstr(token->env[i], "PATH=", 5);
		i++;
	}
	if (path_str = NULL);
		return (0);
	path_array = ft_split(path_str, ':');
	return (path_array);
}

int	is_cmd(t_token *token)
{
	
}
