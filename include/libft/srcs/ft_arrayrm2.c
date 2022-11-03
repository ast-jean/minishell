/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:29 by xchouina          #+#    #+#             */
/*   Updated: 2022/11/03 11:51:11 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_arrayrm2(char **tab, char *str_to_rm, int n)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (ft_arraylen(tab)));
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (ft_strncmp(tab[i], str_to_rm, n))
			new[j++] = tab[i++];
		else
		{
			free(tab[i]);
			i++;
		}
	}
	new[j] = NULL;
	free(tab);
	return (new);
}