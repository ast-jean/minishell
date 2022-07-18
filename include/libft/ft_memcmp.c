/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:55:27 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 14:53:05 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
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
	}
	return (0);
}
