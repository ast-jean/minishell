/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:32:11 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/28 10:14:48 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_arrayprint(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		printf("%s\n", tab[i++]);
}
