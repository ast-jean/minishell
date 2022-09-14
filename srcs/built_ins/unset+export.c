#include "../../include/minishell.h"
// NOTE: Built-ins 2/3 (Unset + Export)

int	builtin_unset(t_vars *vars, char *var_name)
{
// unset (no flag)
	char *name_to_find;

	name_to_find = ft_strjoin(var_name, "=");
	ft_arrayrm(vars->env, ft_arraysrch(vars->env, name_to_find));
		return (1);
}

int	builtin_export(t_token *token, t_vars *vars)
{
printf("in export\n");
// export (no flag) var_name=var_content
char *content;

content = token->next->cont;
if(ft_strchr(content, '='))
{
	ft_arrayadd(vars->env, content);
	// ft_arrayadd(env, content);
}
else
{
/*debug*/printf("\033[41mError with export command\033[0m\n");
}
// cont = ft_single_split(token->next->cont, '=');
/*debug*/printf("var_name= %s\n", token->cont);
/*debug*/printf("line= %s\n", content);
	return (1);
}
