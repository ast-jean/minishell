#include "../../include/minishell.h"
// NOTE: Redirections ( > , < , >>)
// TOFIX  when there is pipe, 0 would overwrite.

int	redirect_input(t_token *token, int fd)
{
	t_token *cpy;

	cpy = token;
	while (ft_strcmp(cpy->cont, "|") != 0 && cpy->next)
	{
		if (ft_strcmp(cpy->cont, "<") == 0)
		{
			fd = open(cpy->next->cont, O_RDONLY);
			cpy = remove_token(cpy);
			cpy->next = remove_token(cpy->next);
		}
		else
			cpy = cpy->next;
	}
	printf("FINAL FDIN = %d\n", fd);
	return (fd);
}

int	redirect_output(t_token *token, int fd)
{
	t_token *cpy;

	cpy = token;
	while (ft_strcmp(cpy->cont, "|") != 0 && cpy->next)
	{
		if (ft_strcmp(cpy->cont, ">") == 0)
		{
			fd = open(cpy->next->cont, O_TRUNC | O_CREAT | O_RDWR, 0777);
			cpy = remove_token(cpy);
			cpy->next = remove_token(cpy->next);
		}
		else if (ft_strcmp(cpy->cont, ">>") == 0)
		{
			fd = open(cpy->next->cont, O_APPEND | O_CREAT | O_RDWR, 0777);
			cpy = remove_token(cpy);
			cpy->next = remove_token(cpy->next);
		}
		else
			cpy = cpy->next;
	}
	printf("FINAL FDOUT = %d\n", fd);
	return (fd);
}
