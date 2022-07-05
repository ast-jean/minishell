/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:54:55 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/03 10:40:02 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\t')
		return (1);
	if (c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	long	num;
	long	n;
	long	i;

	n = 1;
	i = 0;
	num = 0;
	while (s[i] && is_whitespace(s[i]))
		i++;
	if (s[i] == '-')
		n *= -1;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}
	return (num * n);
=======
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:34:17 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 16:03:11 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	neg;
	unsigned int	res;

	res = 0;
	neg = 1;
	while (((*str >= 9 && *str <= 13) || (*str == 32)) && (*str))
		str++;
	if ((*str == '+' || *str == '-') && (*str))
	{
		if (*str == '-')
			neg *= (-1);
		str++;
	}
	while ((*str >= '0' && *str <= '9') && (*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
>>>>>>> main
}
