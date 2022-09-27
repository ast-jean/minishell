#include "../../include/minishell.h"
// NOTE: Built-ins 1/3 (PWD + ENV)


int	builtin_pwd(t_vars *vars)
{
	vars->pwd = ft_arraysrch(vars->env, "PWD=") + 4; 
	printf("%s\n", vars->pwd);
	return (1);
}

int	builtin_env(t_vars *vars)
{
	// char **env_copy;

	// env_copy = ft_arraycpy(vars->env);
	// ft_arrayprint(env_copy);
	ft_arrayprint(vars->env);
	return (1);
}
