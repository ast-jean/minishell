/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:07:50 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/26 13:23:03 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
