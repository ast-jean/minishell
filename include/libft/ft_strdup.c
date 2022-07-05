/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:44:50 by ast-jean          #+#    #+#             */
/*   Updated: 2021/10/18 16:03:06 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:20:56 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/22 14:20:58 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (!cpy)
		return (0);
	cpy = ft_memcpy (cpy, s1, len);
	return (cpy);
=======
static void	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*dup;

	l = ft_strlen(s1);
	dup = malloc(sizeof(char) * (l + 1));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
>>>>>>> main
}
