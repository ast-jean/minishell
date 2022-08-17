/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:09:42 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/28 14:57:12 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_arraycpy(char **tab)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 1));
	i = -1;
	while (tab[++i] != NULL)
		new[i] = tab[i];
	new[i] = NULL;
	return (new);
}
