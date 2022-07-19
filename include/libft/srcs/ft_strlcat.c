/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:31:03 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 14:38:36 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	srcsize;
	size_t	dstsize;

	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (n < dstsize)
		return (srcsize + n);
	else
	{
		dst = dst + dstsize;
		ft_strlcpy(dst, src, n - dstsize);
		return (srcsize + dstsize);
	}
}
