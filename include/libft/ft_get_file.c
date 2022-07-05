/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:18:35 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/20 14:06:04 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 100000

char	*ft_save_line_in_file(char *file, int fd)
{
	int				readcheck;
	char			*output;

	if (!file)
		file = ft_calloc(1, 1);
	output = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readcheck = 1;
	while (!(ft_strchr(file, '\n')) && readcheck > 0)
	{
		readcheck = read(fd, output, BUFFER_SIZE);
		if (readcheck == -1)
		{
			free(output);
			return (NULL);
		}
		output[readcheck] = '\0';
		file = ft_strjoin(file, output);
	}
	free(output);
	return (file);
}

char	*ft_get_file(int fd)
{
	static char	*file[4096];

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	file[fd] = ft_save_line_in_file(file[fd], fd);
	if (!file[fd])
		return (NULL);
	return (file[fd]);
}
