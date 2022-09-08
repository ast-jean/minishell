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
			token->next = remove_token(token->next);
			token = remove_token(token);
		}
		else
			token = token->next;
	}
	// printf("FINAL FDIN = %d\n", fd);
	return (fd);
}

int	redirect_output(t_token *token, int fd_init)
{
	int		group;
	int		fd;

	group = token->group_num;
	fd = fd_init;
	while (ft_strcmp(token->cont, "|") != 0 && token->next)
	{
		if (ft_strcmp(token->cont, ">") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(remove_quotes(token->next->cont), O_TRUNC | O_CREAT | O_RDWR, 0777);
			token->next = remove_token(token->next);
			token = remove_token(token);
		}
		else if (ft_strcmp(token->cont, ">>") == 0)
		{
			if (fd != 1)
				close(fd);
			fd = open(remove_quotes(token->next->cont), O_APPEND | O_CREAT | O_RDWR, 0777);
			token->next = remove_token(token->next);
			token = remove_token(token);
		}
		else
			token = token->next;
	}
	// printf("FINAL FDOUT = %d\n", fd);
	return (fd);
}
