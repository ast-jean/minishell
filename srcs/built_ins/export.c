#include "../../include/minishell.h"

void	ft_export(t_token *token, char **env, t_vars *vars)
{
printf("in export\n");
// export (no flag) var_name=var_content


(void)env;

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

}

