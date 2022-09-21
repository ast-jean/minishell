#include "../../include/minishell.h"
// NOTE: Built-ins 1/3 (PWD + ENV)


int	builtin_pwd(t_vars *vars)
{
// pwd (no flag)
	printf("%s\n", vars->pwd);
	return (1);
}

int	builtin_env(t_vars *vars)
{
// env (no flag)
	char **env_copy;

	printf("\033[46mIn env\033[0m\n");
	env_copy = ft_arraycpy(vars->env);
	ft_arrayprint(env_copy);
	return (1);
}
