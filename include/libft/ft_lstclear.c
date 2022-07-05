/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:33:52 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/03 16:59:28 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:18 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/08 14:25:34 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
<<<<<<< HEAD
	t_list	*temp;
=======
	t_list	*t;
>>>>>>> main

	if (lst)
	{
		while (*lst)
		{
<<<<<<< HEAD
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = temp;
=======
			t = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = t;
>>>>>>> main
		}
	}
}
