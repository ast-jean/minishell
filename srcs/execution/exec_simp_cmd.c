/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_simple_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:59:02 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/07 14:47:35 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	finding_paths(t_vars *vars)
{
	int		i;
	char	*path_str;

	i = 0;
	path_str = 0;
	while (vars->env[i] != NULL)
	{
		if (ft_strnstr(vars->env[i], "PATH=", 5) != NULL)
			path_str = ft_strnstr(vars->env[i], "PATH=", 5);
		i++;
	}
	if (path_str == NULL)
		return ;
	if (vars->path_array != NULL)
		free2d(vars->path_array);
	vars->path_array = ft_split(path_str, ':');
}

int	accessing(t_vars *vars, t_token *token)
{
	char	*cmd;
	int		i;

	if (!token)
		return (-1);
	if (access(remove_quotes(token->cont), F_OK | X_OK) == 0)
	{
		vars->path = remove_quotes(token->cont);
		return (0);
	}
	cmd = ft_strjoin("/", remove_quotes(token->cont));
	i = 0;
	while (vars->path_array[i] != NULL)
	{
		vars->path = ft_strjoin(vars->path_array[i++], cmd);
		if (access(vars->path, F_OK | X_OK) == 0)
		{
			free(cmd);
			return (0);
		}
		free(vars->path);
	}
	free(cmd);
	return (-1);
}
