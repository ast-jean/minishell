

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
		printf("Syntax error near unexpected token 'newline'\n");
	}
	else
		printf("Syntax error near unexpected token '%s'\n", token);
}

int	is_exception(t_token *token)
{
	(void)token;
	return (0);
}

int	check_heredocs(t_vars *vars)
{
	t_token *current;
	char *name;
	int fd;
	char *line;
	int heredoc_count;
	char *delim;

	heredoc_count = 0;
	current = vars->token->first;
	while(current)
	{
		if(!ft_strcmp(current->cont, "<<"))
		{
			line = " ";
			delim = current->next->cont;
// /*debug*/printf("\033[43mdelim = ->|%s|<-\033[0m\n", delim);
			if(!ft_strcmp(delim, ""))
			{
				syntax_error("");
				return (0);
			}
			if(is_exception(current))
			{
				syntax_error(delim);
				return (0);
			}
			name = ft_strjoin(".temp_heredoc", ft_itoa(heredoc_count));
			fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
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
			heredoc_count++;
		}
		else
			current = current->next;
	}
// /*debug*/printf("\033[43m'<<'count:%d\033[0m\n", heredoc_count);
// /*debug*/debug_print_tokens(vars);
	return (1);
}