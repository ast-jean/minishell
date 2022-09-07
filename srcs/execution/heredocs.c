

#include "../../include/minishell.h"

void	syntax_error(char *token)
{
	if(!ft_strcmp(token, ""))
	{
		printf("minishell: syntax error near unexpected token 'newline'\n");
	}
	else
		printf("minishell: syntax error near unexpected token '%s'\n", token);
}

int	is_exception(t_token *token)
{
	if(!token->next->next)
	{
		syntax_error("newline");
		return (0);
	}
	token = token->next;
	if((token->cont[0] == '<') || (token->cont[0] == '>') || (token->cont[0] == '|'))
	{		
		syntax_error(token->cont);
		return (0);
	}
	return (1);
}

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
			new = ft_rmchar(new, &new[i++]);
			while(new[i] && new[i] != quote)
			{
				if(!new[i++])
					break ;
			}
			if(new[i])
				new = ft_rmchar(new, &new[i]);
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
[ ] rm_quotes gives test'test' instead of test"test" for "test"'"test"'
[ ] Add $VAR
[ ] add ctrl-D to finish the heredoc (act like delim)
[ ] fix single quote in delim segfault
[ ] check for leaks
[ ] Norminette
*/
int	check_heredocs(t_vars *vars)
{
	t_token *current;
	char *delim;
	char *name;
	int fd;
	char *line;

	name = calloc(100, sizeof(char));
	current = vars->token->first;
	vars->heredoc_count = 0;
	while(current)
	{
// /*debug*/printf("token = %s\n", current->cont);
		if(!ft_strcmp(current->cont, "<<"))
		{
			line = " ";
			if(!is_exception(current))
				return(0);
			name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
			if(ft_strchr(current->next->cont, '\"') || ft_strchr(current->next->cont, '\''))
				delim = remove_quotes(current->next->cont);
			else
				delim = current->next->cont;
///*debug*/debug_print_tokens(vars);
			fd = open(name, O_RDWR | O_CREAT, 0777);
			new_token_after(current, name);
			while(ft_strcmp(delim, line))
			{
/*debug*/printf("\033[43mdelim = ->|%s|<-\033[0m\n", delim);
				if(ft_strcmp(" ", line))
				{
					line = check_var(line, vars); 
					ft_putstr_fd(line, fd);
				}
				rl_on_new_line();
				line = readline(">");
				rl_redisplay();
			}
			current = remove_token(current, vars);
			current->next = remove_token(current->next, vars);
			vars->heredoc_count++;
		}
		else if(!ft_strcmp(current->cont, "<<<"))
		{
			if(!is_exception(current))
				return(0);
			line = current->next->cont;
			name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
			fd = open(name, O_RDWR | O_CREAT, 0777);
			new_token_after(current, name);
			line = check_var(line, vars);
			ft_putstr_fd(line, fd);
			current = remove_token(current, vars);
			current->next = remove_token(current->next, vars);
		}
		else if((current->cont[0] == '<') && ft_strlen(current->cont) > 3)
		{
			syntax_error("<");
			return (0);
		}
		else
			current = current->next;
	}
/*debug*/debug_print_tokens(vars);
	return (1);
}