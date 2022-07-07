#include "../include/minishell.h"

void	*access_ptr(t_vars *vars, int i)
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

void	debug_print_tokens(t_vars *vars)
{
	int i;

	i = 0;
	// vars->token = vars->token->first;
	printf("Where? Cont=->%p<-\n", vars->token);
	while (vars->token->next != NULL)
	{
		printf("Fault4?\n");
		printf("Token%d Cont=->%s<-\n", i, vars->token->cont);
		printf("Token%d Type=->%s<-\n", i, vars->token->cont);
		vars->token = vars->token->next;
		i++;
	}
}
