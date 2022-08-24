/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:32:11 by xchouina          #+#    #+#             */
/*   Updated: 2022/08/22 13:09:47 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: "ft_arrayprint" prints a double array.

void	ft_arrayprint(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		printf("%s\n", tab[i++]);
}
