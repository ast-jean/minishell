

#include "../../include/minishell.h"



char *remove_quotes(char *str)
{
	int i;
	char quote;
	char *new;

	new = str;
	i = 0;
	while(new[i])
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
			if(new[i])
				new = ft_rmchar(new, &new[i--]);
		}
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}
/*
TODO:
[X] strjoin "this"'test'"one"
[X] rm_quotes gives test'test' instead of test"test" for "test"'"test"'
[ ] Add $VAR
[X] add ctrl-D to finish the heredoc (act like delim)
[X] fix herestring cat: /usr/bin: Is a directory: FIXED by unfreeing line and name
[ ] Fix remove_quotes
	[X] remove quote bug in: "hello"'hello' out: hello'hello
	[ ] Add error if missing a quote
[ ] fix single quote in delim segfault
[ ] check for leaks
[ ] Norminette
*/

void*	check_herestrings(t_token *current, t_vars *vars)
{
	char *name;
	char *line;
	int fd;

	if (!is_exception(current))
		return (NULL);
	line = current->next->cont;
	name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
	if (ft_strchr(current->next->cont, '\"') || ft_strchr(current->next->cont, '\''))
		line = remove_quotes(current->next->cont);
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	new_token_after(current, name);
	line = ft_strjoin(check_var_heredoc(line, vars), "\n");
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
	if (ft_strchr(current->next->cont, '\"') || ft_strchr(current->next->cont, '\''))
		delim = remove_quotes(current->next->cont);
	else
		delim = current->next->cont;
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	new_token_after(current, name);
	while (ft_strcmp(delim, line))
	{
		if (ft_strcmp(" ", line))
		{
			line = ft_strjoin(check_var_heredoc(line, vars), "\n");
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
	free(line);
	return (current);
}

int	check_here(t_vars *vars)
{
	t_token *current;

	current = vars->token->first;
	vars->heredoc_count = 0;
	while(current)
	{
		if (current && current->cont && !ft_strcmp(current->cont, "<<"))
			current = check_heredocs(current, vars);
		else if (current && current->cont && !ft_strcmp(current->cont, "<<<"))
			current = check_herestrings(current, vars);
		else if (current && current->cont && (current->cont[0] == '<') && ft_strlen(current->cont) > 3)
			return (syntax_error("<"));
		else
			current = current->next;
	}
	return (1);
}