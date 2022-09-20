/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/09/20 14:52:09 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTE: removes a char (2nd arg) from the str (1st arg) 
//NOTE: according to its position in the str
//NOTE: Ex: char *str = "AABAA"
//NOTE:		str = ft_rmchar(str , &str[2]);
//NOTE:		printf("%s\n", str);
//NOTE: Out: AAAA
#include "../include/libft.h"

char	*ft_rmchar(char *str, char *s)
{
	char	*new;
	int	 	i;
	int		j;
	int		char_pos;

	i = -1;
	j = 0;
	char_pos = 0;
	new = ft_calloc((ft_strlen(str)), sizeof(char));
	while (s[++i])
		char_pos++;
	i = -1;
	char_pos = ft_strlen(str) - char_pos;
	while (str[++i])
	{
		if (i == char_pos)
			continue ;
		new[j] = str[i];
		j++;
	}
	new[j] = '\0';
	// free(str);
	return (new);
}
