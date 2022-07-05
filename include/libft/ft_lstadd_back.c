/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:27:13 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/03 11:36:14 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:19:20 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/08 14:19:34 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
<<<<<<< HEAD
	t_list	*last;
=======
	t_list	*t;
>>>>>>> main

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
<<<<<<< HEAD
			last = ft_lstlast(*alst);
			last -> next = new;
		}
	}	
=======
			t = ft_lstlast(*(alst));
			t->next = new;
		}
	}
>>>>>>> main
}
