/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:09:16 by mjarry            #+#    #+#             */
/*   Updated: 2022/10/25 11:09:53 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*remove_token(t_token *remove, t_vars *vars)
{
	t_token	*nex;

	if (!remove)
		return (NULL);
	if (remove->next && remove->prev)
	{
		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;
		nex = remove->next;
	}
	else if (!remove->next && remove->prev)
	{
		remove->prev->next = NULL;
		nex = NULL;
	}
	else if (remove->next && !remove->prev)
	{
		remove->next->prev = NULL;
		nex = remove->next;
		while (nex)
		{
			nex->first = remove->next;
			nex = nex->next;
		}
		vars->token = remove->next;
		nex = remove->next;
	}
	else
		nex = NULL;
	if (remove)
	{
		free(remove->cont);
		free(remove);
	}
	return (nex);
}

t_token	*new_token_after(t_token *after_this_one, char *file_name)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	after_this_one->next->prev = new;
	new->cont = file_name;
	new->next = after_this_one->next;
	new->first = after_this_one->first;
	new->prev = after_this_one;
	after_this_one->next = new;
	return (new);
}

void	*access_ptr(t_vars *vars, int i)
{
	int	count;

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
	t_token	*current;
	int		i;

	i = 0;
	current = vars->token->first;
	if (!current)
		return ;
	while (current)
	{
		printf("----------------\n");
		printf("Token %d\n", i);
		printf("Cont=	->%s<-\n", current->cont);
		printf("Ptr=	->%p<-\n", current);
		printf("First=	->%p<-\n", current->first);
		printf("Prev=	->%p<-\n", current->prev);
		printf("Next=	->%p<-\n", current->next);
		current = current->next;
		i++;
	}
	printf("-------END-------\n");
}
