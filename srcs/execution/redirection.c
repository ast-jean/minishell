#include "../../include/minishell.h"
// NOTE: Redirections ( > , < , >>)

int	redirect_input(t_token *token)
{
	int	fd;

	fd = 0;
	while (ft_strcmp(token->cont, "|") != 0 && token->next)
	{
		if (ft_strcmp(token->cont, "<") == 0)
		{
			fd = open(token->next->cont, O_RDONLY);
			//tokenrem x 2 ?
		}
		token = token->next;
	}
	printf("FINAL INPUT = %d\n", fd);
	return (fd);
}

int	redirect_output(t_token *token)
{
	int	fd;

	fd = 1;
	while (ft_strcmp(token->cont, "|") != 0 && token->next)
	{
		if (ft_strcmp(token->cont, ">") == 0)
		{
			fd = open(token->next->cont, O_TRUNC | O_CREAT | O_RDWR, 0777);
			//tokenrem x 2 ?
		}
		else if (ft_strcmp(token->cont, ">>") == 0)
		{
			fd = open(token->next->cont, O_APPEND | O_CREAT | O_RDWR, 0777);
			//tokenrem x 2 ?
		}
		token = token->next;
	}
	printf("FINAL OUTPUT = %d\n", fd);
	return (fd);
}
