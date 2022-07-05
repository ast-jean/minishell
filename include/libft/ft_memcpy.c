/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:34:27 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 12:42:40 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:38:25 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/21 15:38:51 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
<<<<<<< HEAD
	size_t			i;
	unsigned char	*og;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	og = (unsigned char *)dst;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (og);
=======
	size_t		i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	dst = d;
	return (dst);
>>>>>>> main
}
