/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:29:08 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 12:42:26 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:55:27 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 14:53:05 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
<<<<<<< HEAD
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{	
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
=======
	const unsigned char	*x;
	const unsigned char	*y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (x == y || n == 0)
		return (0);
	while (n--)
	{
		if (*x != *y)
			return (*x - *y);
		x++;
		y++;
>>>>>>> main
	}
	return (0);
}
