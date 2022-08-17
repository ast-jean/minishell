#include "../../include/minishell.h"

void	ft_export(char *var_name, char *var_content, char **env, t_vars *vars)
{
// export (no flag)
	char *line;

	var_name = ft_strtoupper(var_name);
	line = ft_strjoin(var_name, "=");
	line = ft_strjoin(line, var_content);
	ft_arrayadd(vars->env, line);
	ft_arrayadd(env, line);
}

