#include "../../include/minishell.h"

int	init_groups(t_vars *vars)
{
	t_token	*copy;
	int		i;

	vars->pipe_count = 0;
	copy = vars->token->first;
	i = 1;
	while (copy->next)
	{
		while (copy->next && ft_strcmp(copy->cont, "|") != 0)
		{
			copy->group_num = i;
			copy = copy->next;
		}
		if (ft_strcmp(copy->cont, "|") == 0)
		{
			vars->pipe_count++;
			// copy = copy->next;
			copy = remove_token(copy);
		}
		i++;
	}
	debug_print_tokens(vars);
	printf("pipecount : %d\n\n", vars->pipe_count);
	if (vars->pipe_count == (i + 1))
		return (-1);
	return (0);
}


// NOTE:

int	parsing_pipes(t_vars *vars)
{
	t_token *cpy;

	cpy = vars->token->first;
	while (cpy->next)
	{
		if (cpy->cont == "|" && cpy->next->cont == "|")
		{
			write(2, "Error.\n", 7);
			return (error_was_made(vars));
		}
		else if (cpy->cont[0] == '|' && cpy->cont[1] == '|')
		{
			write(2, "Error.\n", 7);
			return (error_was_made(vars));
		}
		else if (init_groups(vars) == -1)
		{
			write(2, "Error.\n", 7);
			return (error_was_made(vars));
		}
		cpy = cpy->next;
	}
		return (0);
}