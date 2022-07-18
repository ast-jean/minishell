/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:04:23 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/12 12:04:51 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_iswhitespace(const int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v')
		return (true);
	return (false);
}
