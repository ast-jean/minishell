#include "../../include/minishell.h"
// NOTE: Built-ins 3/3 (Echo + CD)
int	is_n(char *str)
{
	int	i;
	
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

// void	builtin_echo(char **args, char **env)
// {
// 	(void)env;
// 	int	i;

// 	i = 1;
// 	while (ft_strnstr(args[i], "-n", 2) && is_n(args[i]))
// 		i++;
// //start at token "echo" then printf token->next (if not flag) until " | or End of line"
// //look for $var in env and replace 
// 	printf ("%s", args[0 + i]);
// }

int	builtin_echo(t_vars *vars)
{
	t_token *token;

	token = vars->token->next;
	if (ft_strcmp(token->cont, "-n") == 0)
	{
		while (ft_strcmp(token->cont, "|") != 0)
		{
			token = token->next;
			printf("%s", token->cont);
		}
	}
	if (ft_strcmp(token->cont, "-n") != 0)
	{
		while (ft_strcmp(token->cont, "|") != 0)
		{
			printf("%s", token->cont);
			token = token->next;
		}
	}

// IF	TOKEN n+0 = echo
// 		TOKEN n+1 = -n | words
//		TOKEN n+l = words
	return (1);
}

// int	ft_cd(char *arg, char **env)
// {
// // cd (only relative path or absolute)
// //change pwd and oldpwd in env, maybe?
// // save pwd in struct and env
	// return (1);
// }

