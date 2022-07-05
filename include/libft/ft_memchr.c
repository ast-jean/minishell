/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:14:42 by ast-jean          #+#    #+#             */
/*   Updated: 2021/09/17 15:53:57 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:52:02 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 14:50:48 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
<<<<<<< HEAD
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
			return (str);
		str++;
		i++;
=======
	unsigned char	t;
	unsigned char	*str;

	str = (unsigned char *) s;
	t = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*str == t)
			return (str);
		i++;
		str++;
>>>>>>> main
	}
	return (NULL);
}
