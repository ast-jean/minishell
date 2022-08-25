#include "../../include/minishell.h"

void	ft_export(t_token *token, char **env, t_vars *vars)
{
printf("in export\n");
// export (no flag) var_name=var_content
	
// char *line;
(void)env;
(void)vars;

printf("var_name= %s\n", token->cont);
// printf("line= %s\n", line);
// 	ft_arrayadd(vars->env, line);
// 	ft_arrayadd(env, line);
}

