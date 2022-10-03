#include "../../include/minishell.h"


// void	to_name(t_vars *vars, char **split, int *i)
// {
// 	t_token	*current;

// 	while (split[*i] != NULL)
// 	{
// 		current->next = malloc(sizeof(t_token));
// 		current->next->prev = current;
// 		current->next->first = current->first;
// 		current = current->next;
// 		current->cont = split[(*i)++];
// 	}
// }

int	creating_tokens(char *line, t_vars *vars)
{
	char	**split;
	t_token	*current;
	int		i;

	i = 0;
	split = tokenize(line);
	if (!split)
	{
		ft_putstr_fd("minishell: syntax error missing quote\n", 2);
		return (0);
	}
	vars->token = malloc(sizeof(t_token));
	current = vars->token;
	current->cont = split[i++];
	current->first = current;
	current->prev = NULL;
	// to_name(vars, split, &i);
	while (split[i] != NULL)
	{
		current->next = malloc(sizeof(t_token));
		current->next->prev = current;
		current->next->first = current->first;
		current = current->next;
		current->cont = split[i++];
	}
	current->next = NULL;
	free(split);
	return (0);
}
