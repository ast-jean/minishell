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
void	ft_pwd(char **env)
{
// pwd (no flag)
	int		i;

	i = -1;
	while(env[++i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
			printf("%s\n", env[i] + 4);
	}
}
void	ft_export(void)
{
// export (no flag)
}

void ft_unset(void)
{
// unset (no flag)
}

void	ft_env(char **env)
{
// env (no flag)
	char	*pwd;
	int		i;

	i = -1;
	pwd = "";
	while(env[++i])
		printf("%s\n", env[i]);
}
