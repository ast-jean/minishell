/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_alnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:03:35 by ast-jean          #+#    #+#             */
/*   Updated: 2022/08/31 16:14:38 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_is_str_alnum(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}
