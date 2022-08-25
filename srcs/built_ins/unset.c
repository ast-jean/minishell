#include "../../include/minishell.h"


void ft_unset(t_vars *vars, char *var_name)
{
// unset (no flag)
	char *name_to_find;

	name_to_find = ft_strjoin(var_name, "=");
	ft_arrayrm(vars->env, ft_arraysrch(vars->env, name_to_find));
}
