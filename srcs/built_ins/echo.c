#include "../../include/minishell.h"
// NOTE: Built-ins 3/4 (Echo)
int	is_n(char *str)
{
	int	i;
	
	i = 1;
	while (str[i] != '\n')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

char *rm_quotes_echo(char *old)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = malloc(sizeof(char*) * ft_strlen(old));
	while (old[++i] != '\n')
	{
		if (old[i] != '\"' || old[i] != '\'')
			i++;
		else
			new[j++] = old[i];
	}
	return (new);
}

int	builtin_echo(t_vars *vars)
{
	t_token *token;
	bool	n;

	n = false;
	token = vars->token->next;
	while (is_n(remove_quotes(token->cont)))
	{
		n = true;
		token = token->next;
	}
	// dprintf(2, "TOKEN CONT = %s\n", token->cont)
	while (token && ft_strcmp(token->cont, "|") != 0 )
	{
		// printf("\033[46m check_var-> %s\033[46m\n", check_var(token->cont, vars));
		// ft_putstr_fd(token->cont, 1);
		ft_putstr_fd(remove_quotes(check_var(token->cont)), 1);
		if (token->next != NULL) 
			write(1, " ", 1);
		token = token->next;
	// dprintf(2, "im here\n");
	}
	if (n == false)
		dprintf(2, "eeeeeee");
		ft_putstr_fd("\n", 1);
	// else
		// return (0);
	return (0);
}
