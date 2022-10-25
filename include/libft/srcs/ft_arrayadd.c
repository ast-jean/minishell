/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/25 12:10:40 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: 	"ft_arrayadd" adds an allocated str (2nd param.) 
// NOTE:	 at the end of a double array (1st param.).

char	**ft_arrayadd(char **tab, char *str_to_add)
{
	char	**new;
	int		i;

	if (str_to_add == NULL)
		return (tab);
	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 2));
	i = 0;
	while (tab && tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i++] = str_to_add;
	new[i] = NULL;
	if (tab)
		free(tab);
	return (new);
}
