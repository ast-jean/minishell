/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:18:35 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/08 12:44:53 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 1

char	*save_line_in_file(char *file, int fd)
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

char	*file_to_str(char *file)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (file[0] == '\0')
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	j = 0;
	while (file[i] != '\0' && file[i] != '\n')
		temp[j++] = file[i++];
	if (file[i] && file[i] == '\n')
		temp[j] = '\n';
	return (temp);
}

char	*new_file(char *file)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(file) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (file[i])
		str[j++] = file[i++];
	free(file);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*file[4096];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	file[fd] = save_line_in_file(file[fd], fd);
	if (!file[fd])
		return (NULL);
	temp = file_to_str(file[fd]);
	file[fd] = new_file(file[fd]);
	close(fd);
	return (temp);
}
