/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/10/31 17:53:50 by ast-jean         ###   ########.fr       */
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

char	*if_string(char *str, char c, char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc((int)(ft_strlen(str)) + 2, sizeof(char));
	while (str[i] && i < get_pos(str, s))
		new[j++] = str[i++];
	new[j++] = c;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_charadd(char *str, char c, char *s)
{
	char	*new;

	if (!str)
	{
		new = ft_calloc(2, sizeof(char));
		new[0] = c;
	}
	else
		new = if_string(str, c, s);
	free(str);
	str = ft_strdup(new);
	free(new);
	return (str);
}
