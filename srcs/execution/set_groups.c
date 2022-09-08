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
			(vars->pipe_count)++;
			// copy = copy->next;
			copy = remove_token(copy);
		}
		i++;
	}
			// dprintf(2, "hello\n");
	// printf("pipecount : %d\n\n", vars->pipe_count);
	if (vars->pipe_count >= (i - 1))
		return (-1);
	return (0);
}

int	parsing_pipes(t_vars *vars)
{
	t_token *cpy;

	cpy = vars->token->first;
	if (cpy->cont[0] == '|')
	{
		write(2, "Error.\n", 7);
		return (-1);
	}
	while (cpy->next)
	{
		if ((ft_strcmp(cpy->cont, "|") == 0 && ft_strcmp(cpy->next->cont, "|") == 0))
		{
			write(2, "Error.\n", 7);
			return (-1);
		}
		else if (cpy->cont[0] == '|' && cpy->cont[1] == '|')
		{
			write(2, "Error.\n", 7);
			return (-1);
		}
		cpy = cpy->next;
	}
	if (init_groups(vars) == -1)
	{
		write(2, "Error.\n", 7);
		return (-1);
	}
	return (0);
}

// 