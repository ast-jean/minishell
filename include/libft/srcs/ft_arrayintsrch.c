/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayintsrch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:54:41 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/03 13:13:13 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/libft.h"
// NOTE:	"ft_arrayintsrch" searchs for a str (2nd param.) 
// NOTE:	 in a double array (1st param.) and returns its index position. (int).

int	ft_arrayintsrch(char **tab, char *str_to_find)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], str_to_find, ft_strlen(str_to_find)))
			return (i);
	}
	return (0);
}
