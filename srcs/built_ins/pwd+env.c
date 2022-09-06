#include "../../include/minishell.h"
// NOTE: Built-ins 1/3 (PWD + ENV)

// void	ft_echo(char **args, char **env)
// {
// //echo (with -n)
// (void)args;
// (void)env;
// //start at token "echo" then printf token->next (if not flag) until " | or End of line"
// //look for $var in env and replace 
// 	printf ("");
// }
// void	ft_cd(void)
// {
// // cd (only relative path or absolute)
// //change pwd and oldpwd in env, maybe?
// // save pwd in struct and env
// }
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
