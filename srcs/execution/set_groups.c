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
