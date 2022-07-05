/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:23 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/29 12:06:24 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
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
}
