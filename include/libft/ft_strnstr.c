/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:39:15 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 15:13:43 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*h;

	i = 0;
	h = (char *)haystack;
	n_len = ft_strlen((char *)n);
	if (haystack == n || n_len == 0)
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		while (i + j < len && h[i + j] != '\0' && h[i + j] == n[j])
		{
			j++;
			if (j == n_len)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:08:30 by xchouina          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:32 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (needle[0] == '\0' || needle == NULL)
		return ((char *)haystack);
	h = 0;
	while (haystack[h] && h < len)
	{
		n = 0;
		while (needle[n] == haystack[h + n] && h + n < len)
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack + h);
			n++;
		}
		h++;
	}
	return (0);
>>>>>>> main
}
