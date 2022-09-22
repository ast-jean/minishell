#include "../../include/minishell.h"
// NOTE: Built-ins 1/3 (PWD + ENV)


int	builtin_pwd(void)
{
	ft_putstr_fd(ft_strjoin(getenv("PWD"), "\n"), 1);
	return (1);
}

int	builtin_env(t_vars *vars)
{
	char **env_copy;

	env_copy = ft_arraycpy(vars->env);
	ft_arrayprint(env_copy);
	return (1);
}
