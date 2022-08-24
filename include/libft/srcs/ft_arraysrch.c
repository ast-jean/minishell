/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysrch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:12:02 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/22 13:14:37 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE:	"ft_arraysrch" searchs for a str (2nd param.) 
// NOTE:	 in a double array (1st param.) and returns its position.

char	*ft_arraysrch(char **tab, char *str_to_find)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], str_to_find, ft_strlen(str_to_find)))
			return (tab[i]);
	}
	return ("");
}
