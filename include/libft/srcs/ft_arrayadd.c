/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/24 11:16:05 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: 	"ft_arrayadd" adds an allocated str (2nd param.) 
// NOTE:	 at the end of a double array (1st param.).

char	**ft_arrayadd(char **tab, char *str_to_add)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 1));
	i = -1;
	while (tab[++i] != NULL)
		new[i] = tab[i];
	new[i] = str_to_add;
	new[++i] = NULL;
	free(tab);
	return (new);
}
