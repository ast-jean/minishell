/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:53:31 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 16:27:56 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:06:59 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 13:07:01 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
<<<<<<< HEAD
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
=======
	char			*res;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
>>>>>>> main
		return (NULL);
	i = 0;
	while (s[i])
	{
<<<<<<< HEAD
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
=======
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
>>>>>>> main
}
