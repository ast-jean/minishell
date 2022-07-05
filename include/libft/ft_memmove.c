/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:48:43 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 12:50:03 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:12 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/21 18:08:49 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

<<<<<<< HEAD
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
=======
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src || !len)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
>>>>>>> main
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
<<<<<<< HEAD
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
=======
		while (++i < len)
			d[i] = s[i];
	}
	return (dest);
>>>>>>> main
}
