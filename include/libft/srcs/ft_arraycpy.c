/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:09:42 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/22 13:41:44 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: "ft_arraycpy" creates a copy of a double array.
char	**ft_arraycpy(char **tab)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 1));
	i = -1;
	while (tab[++i] != NULL)
		new[i] = tab[i];
	new[i] = NULL;
	// ft_arrayfree(tab);
	return (new);
}
