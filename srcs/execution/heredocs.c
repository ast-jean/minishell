

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
	//cat << "'test'"'test'
//input: "<<"'test''lake'
//output: 'test''lake'

//input: '"test"''lake'
//output: "test"lake
	int i;
	int count; //use?
	char quote;
	char *new;

	new = str;
	count = 0; //use?
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
	}
	free(str);
	return (new);
}
/*
TODO:
[X] strjoin "this"'test'"one"
[ ] fix single quote segfault
[ ] add ctrl-D to go finish the heredoc (act like delim)
[ ] Norminette
[ ] check for leaks
*/
int	check_heredocs(t_vars *vars)
{
	t_token *current;
	char *name;
	int fd;
	char *line;
	char *delim;

	current = vars->token->first;
	vars->heredoc_count = 0;
	while(current)
	{
// /*debug*/printf("token = %s\n", current->cont);
		if(!ft_strcmp(current->cont, "<<"))
		{
			line = " ";
			// delim = current->next->cont;
			if(!is_exception(current))
				return(0);
			delim = remove_quotes(current->next->cont);
///*debug*/debug_print_tokens(vars);
/*debug*/printf("\033[43mdelim = ->|%s|<-\033[0m\n", delim);
			name = ft_strjoin(".tmp/temp_heredoc", ft_itoa(vars->heredoc_count));
			fd = open(name, O_RDWR | O_CREAT, 0777);
			new_token_after(current, name);
			while(ft_strcmp(delim, line))
			{
				if(ft_strcmp(" ", line))
					dprintf(fd, "%s\n", line);
				rl_on_new_line();
				line = readline(">");
				rl_redisplay();
			}
			current = remove_token(current);
			current->next = remove_token(current->next);
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
			dprintf(fd, "%s\n", line);
			current = remove_token(current);
			current->next = remove_token(current->next);
		}
		else if((current->cont[0] == '<') && ft_strlen(current->cont) > 3)
		{
			syntax_error("<");
			return (0);
		}
		else
			current = current->next;
	}
// /*debug*/printf("\033[43m'<<'count:%d\033[0m\n", heredoc_count);
	return (1);
}