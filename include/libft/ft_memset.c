/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:00:27 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 12:50:33 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:44:38 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 14:49:02 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
<<<<<<< HEAD
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
=======
	char	*str;
	size_t	i;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
>>>>>>> main
		i++;
	}
	return (b);
}
