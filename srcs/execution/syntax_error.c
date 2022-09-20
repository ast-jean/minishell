

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
