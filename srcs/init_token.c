#include "../include/minishell.h"

char	*defining_token_type(t_token *token)
{
	if (token->cont[0] == '-')
		return ("flag");
	//else if file
		return ("file");
	//else if cmd
		return ("cmd");
}


void	*push_tk(char *cont, t_token *token, t_token *first)
{
	token->cont = line_content[i];
	token->type = defining_token_type(&token);
	token->first = first_first;
	token->next = malloc(sizeof(t_token));
}

void	*creating_tokens(char *line, t_vars *vars)
{
	char **line_content;
	int i;
	t_token *token;
	t_token *first_first;
	t_token *prev_prev;

	// line_content = splitting_tokens(line); //Change split later
	
	i = 0;
	token = malloc(sizeof(t_token));
	first_first = token;
	prev_prev = NULL;

	while (line_content[i])
	{
		push_tk(line_content[i], token, first_first, prev_prev)
		prev_prev = token;
		token = token->next;
		i++;
	}

}


