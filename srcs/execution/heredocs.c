

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

int	check_heredocs(t_vars *vars)
{
	t_token *current;
	char *name;
	int fd;
	char *line;
	int heredoc_count;
	char * delim;

	heredoc_count = 0;
	line = " ";
	current = vars->token->first;
	delim = current->next->next->cont;
	while(current)
	{
		if(!ft_strcmp(current->cont, "<<"))
		{

			if(!current->next->cont || !ft_strcmp(current->next->cont, "<<"))
			{
				printf("Error: << needs delimiter\n");
				return(0);
			}
			name = ft_strjoin(".temp_heredoc", ft_itoa(heredoc_count));
			fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
/*debug*/printf("\033[43mdelim = ->|%s|<-\033[0m\n", delim);
			new_token_after(current, name);
			while(ft_strcmp(delim, line))
			{
				rl_on_new_line();
				line = readline(">");
				dprintf(fd, "%s\n", line);
				rl_redisplay();
			}
			current = remove_token(current);
			heredoc_count++;
		}
		else
			current = current->next;
	}
/*debug*/printf("\033[43m'<<'count:%d\033[0m\n", heredoc_count);
	debug_print_tokens(vars);
	return (1);
}