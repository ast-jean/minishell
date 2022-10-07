/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/10/05 12:28:15 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTE:add a char (2nd arg) in the str (1st arg) 
//NOTE:after the pointed char (2rd)
//NOTE: Ex: char *str = "AAAA"
//NOTE:		str = ft_addchar(str , &str[2]);
//NOTE:		printf("%s\n", str);
//NOTE: Out: AABAA
#include "../include/libft.h"

int	get_pos(char *str, char *s)
{
	int	pos;

	pos = 0;
	while (s[pos])
		pos++;
	if (str)
		return (ft_strlen(str) - pos + 1);
	else
		return (0);
}

char	*ft_addchar(char *str, char c, char *s)
{
	char	*old_temp;
	char	*new;
	int		i;
	int		j;

	old_temp = str;
	i = 0;
	j = 0;
	if (!str)
	{
		new = ft_calloc(2, sizeof(char));
		new[0] = c;
	}
	else
	{
		new = ft_calloc((int)(ft_strlen(str)) + 2, sizeof(char));
		while (old_temp[i] && i < get_pos(str, s))
			new[j++] = old_temp[i++];
		new[j++] = c;
		while (old_temp[i])
			new[j++] = old_temp[i++];
		new[j] = '\0';
	}
	return (new);
}
