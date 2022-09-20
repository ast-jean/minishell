#include "../../include/minishell.h"

void free_tokens(t_vars *vars)
{
	t_token *temp;

	temp = vars->token->first;
	while (vars && temp)
	{
		// printf("token->%s\n", temp->cont);
		temp = temp->next;
		free((temp->prev));
	}
}

void	quit_shell(t_vars *vars)
{
	(void)vars;
	// free_tokens(vars);
	//delete history

	exit(0);
	// kill(SIGABRT, 0);
}

