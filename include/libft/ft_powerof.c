/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:19:00 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/02 16:17:04 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_powerof(int num, int power)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (++i <= power)
		result *= num;
	return (result);
}
