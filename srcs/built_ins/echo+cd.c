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

int	builtin_echo(t_vars *vars)
{
	t_token *token;
	bool	n;

	token = vars->token->next;
	// TOFIX add remove_quotes() somewhere
	while (token && ft_strcmp(token->cont, "|") != 0)
	{
		if (is_n(token->cont))
			n = true;
		else
		{
			ft_putstr_fd(token->cont, 1);
			if (token->next)
				write(1, " ", 1);
		}
		token = token->next;
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


// int	finding_pwd(t_vars *vars)
// {
// 	int	i;
// 	int	p;

// 	i = -1;
// 	while (vars->env[++i] != NULL)
// 	{
// 		if (ft_strnstr(vars->env[i], "PWD=", 4) != NULL)

		
// 	}
// }

// int	builtin_cd(t_vars *vars)
// {
// 	t_token *token;

// 	if (token->next->cont == "..")
// 	{
		
// 	}
// }
// int	ft_cd(char *arg, char **env)
// {
// // cd (only relative path or absolute)
// //change pwd and oldpwd in env, maybe?
// // save pwd in struct and env
	// return (1);
// }

