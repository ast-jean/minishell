/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:23:30 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/03 17:16:20 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:22:19 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 15:16:05 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> main
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
<<<<<<< HEAD
	int		len;

	len = ft_strlen((char *)s);
	while (0 != len && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
=======
	int	i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)(&(s[i])));
	}
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
>>>>>>> main
	return (NULL);
}
