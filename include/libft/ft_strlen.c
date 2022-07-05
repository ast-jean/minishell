/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:52:21 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 13:06:42 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:39:34 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 14:54:09 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
<<<<<<< HEAD
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
=======
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
>>>>>>> main
}
