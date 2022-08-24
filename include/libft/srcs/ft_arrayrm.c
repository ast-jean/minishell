/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:13:13 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/22 13:41:39 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: "ft_arrayrm" removes a str (2nd param.) in a double array (1st param.).

char	**ft_arrayrm(char **tab, char *str_to_rm)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (ft_arraylen(tab) - 1));
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (tab[i] != str_to_rm)
			new[j++] = tab[i++];
		else
			i++;
	}
	// ft_arrayfree(tab);
	return (new);
}
