/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_skipgrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:43 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/05 13:09:53 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*skip_group(t_token *current_token)
{
	int	t;

	t = current_token->group_num;
	while (current_token->next != NULL && current_token->group_num == t)
		current_token = current_token->next;
	return (current_token);
}
