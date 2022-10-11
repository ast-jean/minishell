/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:12:27 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/07 15:55:07 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*last_token(t_token *current, t_vars *vars)
{
	current = vars->token;
	while (current->next)
		current = current->next;
	return (current);
}

char	*remove_quotes(char *str)
{
	int		i;
	char	quote;
	char	*new;

	new = calloc(ft_strlen(str) + 1, sizeof(char));
	new = ft_strcpy(new, str);
	i = 0;
	while (new && new[i])
	{
		if (new[i] == '\"' || new[i] == '\'')
		{
			quote = new[i];
			new = ft_charrm(new, &new[i]);
			while (new[i] && new[i] != quote)
			{
				if (!new[i++])
					break ;
			}
			if (new[i])
				new = ft_charrm(new, &new[i--]);
		}
		i++;
	}
	// if (str)
	// 	free(str);
	return (new);
}

t_token	*check_herestrings(t_token *current, t_vars *vars)
{
	char	*name;
	char	*line;
	int		fd;

	if (!is_exception(current))
		return (NULL);
	line = current->next->cont;
	name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	new_token_after(current, name);
	line = ft_strjoin(check_var(line, vars), "\n");
	line = remove_quotes(line);
	ft_putstr_fd(line, fd);
	current = remove_token(current, vars);
	current = remove_token(current->next, vars);
	if (current == NULL)
		current = last_token(current, vars);
	return (current);
}

int	check_here(t_vars *vars)
{
	t_token	*current;

	current = vars->token->first;
	vars->heredoc_count = 0;
	while (current)
	{
		if (current && current->cont && !ft_strcmp(current->cont, "<<"))
		{
			current = check_heredocs(current, vars);
			if (!current)
				return (0);
		}
		else if (current && current->cont && !ft_strcmp(current->cont, "<<<"))
		{
			current = check_herestrings(current, vars);
			if (!current)
				return (0);
		}
		else if (current && current->cont && (current->cont[0] == '<')
			&& ft_strlen(current->cont) > 3)
			return (syntax_error("<"));
		else
			current = current->next;
	}
	return (1);
}
