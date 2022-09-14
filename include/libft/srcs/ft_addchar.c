/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/09/14 14:22:41 by ast-jean         ###   ########.fr       */
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
	int pos;

	pos = 0;
	while(s[pos])
	{
		pos++;
	}
	return(ft_strlen(str) - pos + 1);
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
	new = ft_calloc((int)(ft_strlen(str)) + 2, sizeof(char)); //change calloc pour ft_calloc
	while(old_temp[i] && i < get_pos(str, s))
		new[j++] = old_temp[i++];
	new[j++] = c;
	while(old_temp[i])
		new[j++] = old_temp[i++];
	new[j] = '\0';
	// free(str);
	return (new);
}