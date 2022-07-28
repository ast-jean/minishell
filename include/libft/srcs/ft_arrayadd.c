/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/28 10:43:29 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_arrayadd(char **tab, char *str_2_add)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 1));
	i = -1;
	while (tab[++i] != NULL)
		new[i] = tab[i];
	new[i] = str_2_add;
	new[++i] = NULL;
	return (new);
}
