/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:18:19 by xchouina          #+#    #+#             */
/*   Updated: 2021/11/03 13:07:28 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
//----------------------------------------------------------

static void	ft_fill(int len, int offset, int n, char *res)
{
	while (len > offset)
	{
		res[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
}
//----------------------------------------------------------

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		offset;

	len = ft_len(n);
	offset = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill(len, offset, n, res);
	res[len] = '\0';
	return (res);
}
