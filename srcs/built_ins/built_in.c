#include "../../include/minishell.h"

void	ft_echo(char **args, char **env)
{
//echo (with -n)
(void)args;
(void)env;
//start at token "echo" then printf token->next (if not flag) until " | or End of line"
//look for $var in env and replace 
	printf ("");
}
void	ft_cd(void)
{
// cd (only relative path or absolute)
//change pwd and oldpwd in env, maybe?
// save pwd in struct and env
}
void	ft_pwd(t_vars *vars)
{
// pwd (no flag)
	printf("%s\n", vars->pwd);
}

void ft_unset(void)
{
// unset (no flag)
}

void	ft_env(t_vars *vars)
{
// env (no flag)
	ft_arrayprint(vars->env);
}
