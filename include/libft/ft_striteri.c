/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:53:31 by ast-jean          #+#    #+#             */
/*   Updated: 2021/11/02 13:02:44 by ast-jean         ###   ########.fr       */
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:16:02 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 12:49:38 by xchouina         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

<<<<<<< HEAD
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
=======
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
>>>>>>> main

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
<<<<<<< HEAD
		f(i, s + i);
		i++;
	}
	s[i] = '\0';
=======
		f(i, &s[i]);
		i++;
	}
>>>>>>> main
}
