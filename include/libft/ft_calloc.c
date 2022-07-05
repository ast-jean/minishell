/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:37:20 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 12:23:13 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:09:22 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 13:09:34 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
<<<<<<< HEAD
	void	*ptr;

	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
=======
	char	*x;

	x = malloc(size * count);
	if (!x)
		return (NULL);
	ft_memset(x, 0, count * size);
	return (x);
>>>>>>> main
}
