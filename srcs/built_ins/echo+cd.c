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
// NEW : WORK IN PROGRESS
int	builtin_echo(t_vars *vars)
{
	t_token *token;
	bool	n;

	token = vars->token->next;
	
	while (token && ft_strcmp(token->cont, "|") != 0)
	{
		if (is_n(token->cont))
		{
			token = token->next;
			n = true;
		}
		else
			ft_putstr_fd(token->cont, 1);
	}
	if (n == true)
		return (0);
	else
		ft_putstr_fd("\n", 1);
	return (0);
}

// 	if (token && ft_strcmp(token->cont, "-n") == 0)
// 	{
// 		token = token->next;
// 		while (token && ft_strcmp(token->cont, "|") != 0)
// 		{
// 			ft_putstr_fd(token->cont, 1);
// 			token = token->next;
// 		}
// 	}
// 	else if (token && ft_strcmp(token->cont, "-n") != 0)
// 	{
// 		while (token && ft_strcmp(token->cont, "|") != 0)
// 		{
// 			ft_putstr_fd(token->cont, 1);
// 			token = token->next;
// 		}
// 	}
// 	else if (!token)
// 		write(1, "\n", 1);
// 	return (1);
// }
// NEW WORK IN PROGRESS


//  -nnnnnnnnnnnnnnnnnnnnnnnnnnn
//  -n -n- n- n-n--n-n-n n--n--n-n-n-
// IF	TOKEN n+0 = echo
// 		TOKEN n+1 = -n | words
//		TOKEN n+l = words

// int	ft_cd(char *arg, char **env)
// {
// // cd (only relative path or absolute)
// //change pwd and oldpwd in env, maybe?
// // save pwd in struct and env
	// return (1);
// }

