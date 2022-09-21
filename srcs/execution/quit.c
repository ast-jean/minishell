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
	// t_token *temp;
	int	i = 0;
	// (void)vars;
	while (vars->env[i])
		free(vars->env[i++]);
	free (vars->env);
	// if (vars->token)
	// 	temp = vars->token->first;
	// while (temp)
	// {
	// 	vars->token = temp;
	// 	free(vars->token->cont);
	// 	temp = vars->token->next;
	// 	// free(vars->token);
	// }
	// free(vars);
	//delete history

	exit(0);
	// kill(SIGABRT, 0);
}

