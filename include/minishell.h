#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


// STRUCTS

typedef struct s_vars
{
	int		ac;
	char	**av;
	char 	**env;
	t_token	*token;
}	t_vars

typedef struct s_token
{
	char	*cont;
	char 	*type;
	void	*next;
	void	*first;
	void	*last;
}	t_token

// FUNCTIONS (SELON FILENAME)----------------------

// MINISHELL.C

// PARSING.C
void	creating_tokens(char *line);


// ------------------------------------------------
#endif