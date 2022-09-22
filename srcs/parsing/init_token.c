#include "../../include/minishell.h"

// void	init_token_null(t_token *token, t_token *fi)
// {
// 	token->cont = "";
// 	token->next = NULL;
// 	token->first = fi;
// 	token->prev = NULL;
// }

// int	count_list(char **list)
// {
// 	int	i;

// 	i = 0;
// 	while (list[i])
// 		i++;
// 	return (i);
// }

// int	creating_tokens(char *line, t_vars *vars)
// {
// 	char	**line_content;
// 	int		i;
// 	int		count;
// 	t_token	*first_first;
// 	t_token	*prev_prev;

// 	line_content = tokenize(line);
// 	if (!line_content)
// 	{
// 		ft_putstr_fd("error: missing quote\n", 2);
// 		return (-1);
// 	}
// 	count = count_list(line_content);
// 	i = 0;
// 	vars->token = malloc(sizeof(t_token));
// 	first_first = vars->token;
// 	prev_prev = NULL;
// 	while (line_content[i])
// 	{
// 		push_tk(line_content[i], vars->token, first_first, prev_prev, i, count);
// 		prev_prev = vars->token;
// 		vars->token = vars->token->next;
// 		init_token_null(vars->token, first_first);
// 		i++;
// 	}
// 	vars->token = vars->token->first;
// 	return (0);
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
