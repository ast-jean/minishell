/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:27:36 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 20:54:26 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:28:56 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/08 14:28:57 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
<<<<<<< HEAD
	while (lst)
	{	
		f(lst->content);
		lst = lst -> next;
=======
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
>>>>>>> main
	}
}
