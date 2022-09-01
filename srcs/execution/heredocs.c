

#include "../../include/minishell.h"

t_token *remove_token(t_token *remove)
{
	t_token *nex;

	nex = remove->next;
	remove->prev->next = remove->next;
	remove->next->prev = remove->prev;
	free(remove);
	return (nex);
}

t_token	*new_token_after(t_token *after_this_one, char* file_name)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	after_this_one->next->prev = new;
	new->cont = file_name;
	new->next = after_this_one->next;
	new->first = after_this_one->first;
	new->prev = after_this_one;
	after_this_one->next = new;
	return (new);
}


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
	if (str[0] == 34)
		return (ft_strtrim(str, "\""));
	else if(str[0] == 39)
		return (ft_strtrim(str, "\'"));
	else
		return (str);
}

/*
TODO:
[ ] Norminette
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
		if(!ft_strcmp(current->cont, "<<"))
		{
			line = " ";
			delim = current->next->cont;
			if(!is_exception(current))
				return(0);
			delim = remove_quotes(current->next->cont);
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
// /*debug*/debug_print_tokens(vars);
	return (1);
}