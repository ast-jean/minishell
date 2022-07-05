/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:46:35 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 19:21:08 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:11 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 16:59:47 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
<<<<<<< HEAD
	if (!alst || !new)
		return ;
	new -> next = *alst;
	*alst = new;
	return ;
=======
	new->next = *alst;
	*alst = new;
>>>>>>> main
}
