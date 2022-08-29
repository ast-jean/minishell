#include "../../include/minishell.h"

void	*access_ptr(t_vars *vars, int i) //dont know if it works
{
	int count;

	count = 0;
	vars->token = vars->token->first;
	while (count <= i)
	{
		vars->token = vars->token->next;
	}
	return (vars->token);
}

void	push_tk(char *cont, t_token *token, t_token *first, t_token *prev, int i, int count)
{
	token->cont = cont;
	token->prev = prev;
	// token->type = defining_token_type(token);
	token->first = first;
	if (i < count)
		token->next = malloc(sizeof(t_token));
	else
		token->next = NULL;
}

void	debug_print_tokens(t_vars *vars)
{
	t_token *current;
	int i;

	i = 0;
	current = vars->token->first;
	while (current->cont != NULL)
	{
		printf("----------------\n");
		printf("Token %d\n",i);
		printf("Cont=	->%s<-\n", current->cont);
		printf("Type=	->%s<-\n", current->type);
		printf("Ptr=	->%p<-\n", current);
		printf("First=	->%p<-\n", current->first);
		printf("Prev=	->%p<-\n", current->prev);
		printf("Next=	->%p<-\n", current->next);
		current = current->next;
		i++;
	}
	printf("----------------\n");
}
