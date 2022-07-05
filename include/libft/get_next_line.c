/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:13:13 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/15 13:54:37 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 100

char	*ft_read_rmd(int fd, char *rmd)
{
	char	*buff;
	int		l;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	l = 1;
	while (!ft_strchr(rmd, '\n') && l != 0)
	{
		l = read(fd, buff, BUFFER_SIZE);
		if (l == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[l] = '\0';
		rmd = ft_strjoin(rmd, buff);
	}
	free(buff);
	return (rmd);
}

char	*get_next_line(int fd)
{
	char			*temp;
	static char		*rmd;

	rmd = ft_read_rmd(fd, rmd);
	if (!rmd)
		return (NULL);
	temp = ft_get_temp(rmd);
	rmd = ft_new_rmd(rmd);
	return (temp);
}
