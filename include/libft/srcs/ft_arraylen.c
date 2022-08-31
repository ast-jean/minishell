/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:07:50 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/31 11:15:55 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: "ft_arraylen" counts the length of x (where tab[x][y]).

int	ft_arraylen(char **tab)
{
	int	len;

	len = 0;
	while (tab && tab[len])
		len++;
	return (len);
}
