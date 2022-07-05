/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:31:47 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/02 16:11:30 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:07:58 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/21 14:08:02 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (0 < size)
	{
		while (src[i] && i < (size - 1))
=======
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (--dstsize && src[i])
>>>>>>> main
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
<<<<<<< HEAD
	return (ft_strlen(src));
=======
	while (src[i])
		i++;
	return (i);
>>>>>>> main
}
