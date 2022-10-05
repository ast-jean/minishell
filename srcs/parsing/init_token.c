/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:51:20 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 12:51:23 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*token_loop(t_token *current, char **split, int *i)
{
	while (split[*i] != NULL)
	{
		current->next = malloc(sizeof(t_token));
		current->next->prev = current;
		current->next->first = current->first;
		current = current->next;
		current->cont = split[(*i)++];
	}
	return (current);
}

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
	current = token_loop(current, split, &i);
	current->next = NULL;
	free(split);
	return (0);
}
