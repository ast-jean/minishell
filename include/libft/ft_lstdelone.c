/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:15:03 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/03 16:43:03 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:21:17 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/08 14:21:36 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
<<<<<<< HEAD
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
=======
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
>>>>>>> main
}
