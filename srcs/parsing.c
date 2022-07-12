#include "../include/minishell.h"

void	creating_tokens(char *line)
{
	t_vars	*vars;
	char	**line_content;
	char 	*token;

	int i;
	line_content = ft_split_tk(line); //Change split later

	while (line_content[i] != NULL)
	{
		token->cont = line_content[i];
		token->type = defining_token_type();
		token->next = malloc(sizeof(t_token));
		i++;
	}
	token = token->next;
}

void	defining_token_type(t_token token)
{
	if (vars->token[n]->cont[0] == '-')
		return ("flag");
	//else if file
		return ("file");
	//else if cmd
		return ("cmd");
}
