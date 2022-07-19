/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:22:20 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/09 11:53:18 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *rmd, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!rmd)
// 	{
// 		rmd = (char *)malloc(1 * sizeof(char));
// 		rmd[0] = '\0';
// 	}
// 	if (!rmd || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(rmd) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (rmd)
// 		while (rmd[++i] != '\0')
// 			str[i] = rmd[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(rmd) + ft_strlen(buff)] = '\0';
// 	free(rmd);
// 	return (str);
// }

char	*ft_get_temp(char *rmd)
{
	int		i;
	char	*str;

	i = 0;
	if (!rmd[i])
		return (NULL);
	while (rmd[i] && rmd[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rmd[i] && rmd[i] != '\n')
	{
		str[i] = rmd[i];
		i++;
	}
	if (rmd[i] == '\n')
	{
		str[i] = rmd[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_rmd(char *rmd)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rmd[i] && rmd[i] != '\n')
		i++;
	if (!rmd[i])
	{
		free(rmd);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rmd) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rmd[i])
		str[j++] = rmd[i++];
	str[j] = '\0';
	free(rmd);
	return (str);
}
