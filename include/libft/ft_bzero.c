/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:25:21 by ast-jean          #+#    #+#             */
/*   Updated: 2021/09/15 13:33:58 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:06:45 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/21 18:08:02 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
<<<<<<< HEAD
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
=======
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (n == 0)
		return ;
	while (i < n)
		str[i++] = 0;
	return ;
>>>>>>> main
}
