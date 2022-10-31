/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marie-soleiljarry <marie-soleiljarry@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/10/29 10:51:47 by marie-solei      ###   ########.fr       */
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

char	*ft_charadd(char *str, char c, char *s)
{
	char	*new;
	int		i;
	int		j;

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
		while (str[i] && i < get_pos(str, s))
			new[j++] = str[i++];
		new[j++] = c;
		while (str[i])
			new[j++] = str[i++];
		new[j] = '\0';
	}
	str = ft_strcpy(str, new);
	free(new);
	return (str);
}
