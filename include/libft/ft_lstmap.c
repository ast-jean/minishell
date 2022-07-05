/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:45:28 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/03 17:09:48 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:05 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/08 14:41:36 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
<<<<<<< HEAD
	t_list	*new;
	t_list	*temp;
	t_list	*begin;

	if (lst)
	{
		temp = lst;
		begin = ft_lstnew(f(temp->content));
		if (!(begin))
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			new = ft_lstnew(f(temp->content));
			if (!(new))
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, new);
			temp = temp->next;
		}
		return (begin);
	}
	return (NULL);
=======
	t_list	*new_lst;
	t_list	*new_elem;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!(new_elem))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
>>>>>>> main
}
