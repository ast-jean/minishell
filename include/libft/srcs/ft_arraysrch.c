/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysrch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:12:02 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/28 15:33:20 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/libft.h"

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
