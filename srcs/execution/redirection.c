#include "../../include/minishell.h"
// NOTE: Redirections ( > , < , >>)

int	redirect_input(t_token *token, int fd_init)
{
	int	group;
	int fd;

	group = token->group_num;
	fd = fd_init;
	while (token->group_num == group && token->next)
	{
		if (ft_strcmp(token->cont, "<") == 0)
		{
			if (fd != 0)
				close(fd);
			fd = open(remove_quotes(token->next->cont), O_RDONLY);
		}
			token = token->next;
	}
	return (fd);
}

int	redirect_output(t_token *token, int fd_init)
{
	int		group;
	int		fd;

	group = token->group_num;
	fd = fd_init;
	while (token->next && token->group_num == group)
	{
		if (ft_strcmp(token->cont, ">") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(remove_quotes(token->next->cont), O_TRUNC | O_CREAT | O_RDWR, 0777);
		}
		else if (ft_strcmp(token->cont, ">>") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(remove_quotes(token->next->cont), O_APPEND | O_CREAT | O_RDWR, 0777);
		}
			token = token->next;
	}
	return (fd);
}

t_token	*rm2tokens(t_token* token, t_vars *vars)
{
	token->next = remove_token(token->next, vars);
	token = remove_token(token, vars);
	return (token);
}

t_token *rm_redir(t_token *token, t_vars *vars)
{
	int	group;

	group = token->group_num;
	while (token->next && token->next->group_num == group)
	{
		if (ft_strcmp(token->cont, "<") == 0)
			token = rm2tokens(token, vars);
		else if (ft_strcmp(remove_quotes(token->cont), ">") == 0)
			token = rm2tokens(token, vars);
		else if (ft_strcmp(remove_quotes(token->cont), ">>") == 0)
			token = rm2tokens(token, vars);
		else
			token = token->next;
	}
	while (token->prev != NULL && token->prev->group_num == group)
		token = token->prev;
	return (token);
}
