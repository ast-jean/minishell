/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/26 13:03:16 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_arrayadd(char **tab, char *str_2_add)
{
	char	**new;
	int		i;
	
}

int	ft_arraylen(char **tab)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (tab[++i] != NULL)
		len++;
	return (len);
}