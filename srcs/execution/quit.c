#include "../../include/minishell.h"

void	free_tokens(t_vars *vars)
{
	t_token *temp;

	temp = vars->token->first;
	while (vars && temp)
	{
		temp = temp->next;
		free((temp->prev));
	}
}

void	quit_shell(t_vars *vars)
{
	// t_token *temp;
	// int	i = 0;
	// (void)vars;
	if (vars->env)
		free2d(vars->env);
	if (vars->path_array)
		free2d(vars->path_array);
	// free(vars->line);
	// if (vars->token)
		// temp = vars->token->first;
	// while (temp)
	// {
	// 	vars->token = temp;
	// 	free(vars->token->cont);
	// 	temp = vars->token->next;
	// 	// free(vars->token);
	// }
	rl_clear_history();
	exit(0);
	// kill(SIGABRT, 0);
}
