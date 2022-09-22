

#include "../../include/minishell.h"

char *remove_quotes(char *str)
{
	int i;
	char quote;
	char *new;

	new = str;
	i = 0;
	while( new && new[i])
	{
		if(new[i] == '\"' || new[i] == '\'')
		{
			quote = new[i];
			new = ft_rmchar(new, &new[i]);
			while (new[i] && new[i] != quote)
			{
				if(!new[i])
					break ;
				i++;
			}
			if (new[i])
				new = ft_rmchar(new, &new[i--]);
		}
		i++;
	}
	// 	new[i] = '\0'; //caused bus error

	return (new);
}

void*	check_herestrings(t_token *current, t_vars *vars)
{
	char *name;
	char *line;
	int fd;

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
	// free(name);
	// free(line);
	return (current);
}

void*	check_heredocs(t_token *current, t_vars *vars)
{
	char	*line;
	char	*delim;
	char	*name;
	int		fd;

	line = " ";
	if (!is_exception(current))
		return(NULL);
	name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
	delim = remove_quotes(current->next->cont);
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	new_token_after(current, name);
	while (ft_strcmp(delim, line))
	{
		if (ft_strcmp(" ", line))
		{
			line = ft_strjoin(check_var(line, vars), "\n");
			ft_putstr_fd(line, fd);
		}
		rl_on_new_line();
		line = readline(ft_strjoin(delim,"> "));
		if (!line)
			line = delim;
		rl_redisplay();
	}
	current = remove_token(current, vars);
	current = remove_token(current->next, vars);
	vars->heredoc_count++;
	// free(name);
	// free(line);
	return (current);
}

int	check_here(t_vars *vars)
{
	t_token *current;

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
		else if (current && current->cont && (current->cont[0] == '<') && ft_strlen(current->cont) > 3)
			return (syntax_error("<"));
		else
			current = current->next;
	}
	// if (line)
	// 	free(line);
	return (1);
}
