

#include "../../include/minishell.h"

int	syntax_error(char *token)
{
	if(!ft_strcmp(token, ""))
		printf("minishell: syntax error near unexpected token 'newline'\n");
	else
		printf("minishell: syntax error near unexpected token '%s'\n", token);
	return (0);
}

int	is_exception(t_token *token)
{
	if(!token->next->next)
		return (syntax_error("newline"));
	token = token->next;
	if((token->cont[0] == '<') || (token->cont[0] == '>') || (token->cont[0] == '|'))
		return (syntax_error(token->cont));
	return (1);
}

// NOTE: Checking if one of the 2 {',"} quotes are even (if not print error + return(0) ) 
int	check_quotes(char *str)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			j++;
		if (str[i] == '\"')
			k++;
	}
	if (j % 2 != 0)
	{
		ft_putstr_fd("minishell: syntax error with unexpected token \'\n", 2);
		return (0);
	}
	else if (k % 2 != 0)
	{
		ft_putstr_fd("minishell: syntax error with unexpected token \"\n", 2);
		return (0);
	}
	else
		return (1);
}
