#include "../include/minishell.h"

char	*defining_token_type(t_token *token)
{
	if (token->cont[0] == '-')
		return ("flag");
	// else if cmd
	// 	return ("cmd");
	else
		return ("file");

}

int	count_list(char **list)
{
	int i;
	
	i = 0;
	while (list[i])
		i++;
	return(i);
}

void	push_tk(char *cont, t_token *token, t_token *first, t_token *prev, int i, int count)
{
	token->cont = cont;
	token->prev = prev;
	token->type = defining_token_type(token);
	token->first = first;
	if (i < count)
		token->next = malloc(sizeof(t_token));
	else
		token->next = NULL;
	printf("New token\nptr=	%p\nCont=	%s\ntype=	%s\nnext=	%p\nfirst=	%p\n",token, token->cont, token->type, token->next, token->first);
}

void	creating_tokens(char *line, t_vars *vars)
{
	char **line_content;
	int i;
	int count;
	t_token *first_first;
	t_token *prev_prev;
	// line_content = splitting_tokens(line); //Change split later
	line_content = ft_split(line, ' ');
	count = count_list(line_content);
	i = 0;
	vars->token = malloc(sizeof(t_token));
	first_first = vars->token;
	prev_prev = NULL;

	while (line_content[i])
	{
		push_tk(line_content[i], vars->token, first_first, prev_prev, i, count);
		prev_prev = vars->token;
		vars->token = vars->token->next;
		i++;
	}
}


