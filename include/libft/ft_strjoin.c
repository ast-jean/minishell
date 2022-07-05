/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:56:57 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 13:04:44 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:23 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/29 12:06:24 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> main
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
<<<<<<< HEAD
	char	*str;
	size_t	i;
	size_t	j;
	size_t	tot_len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * tot_len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
=======
	size_t	j;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	cat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (NULL);
	j = 0;
	while (*s1)
	{
		cat[j] = *s1;
		s1++;
		j++;
	}
	while (*s2)
	{
		cat[j] = *s2;
		s2++;
		j++;
	}
	cat[j] = '\0';
	return (cat);
>>>>>>> main
}
