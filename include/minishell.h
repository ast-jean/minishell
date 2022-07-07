#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


// STRUCTS
typedef struct s_token
{
	char			*cont;
	char 			*type;
	struct s_token	*next;
	struct s_token	*prev;
	struct s_token	*first;
}	t_token;

typedef struct s_vars
{
	int		ac;
	char	**av;
	char 	**env;
	t_token	*token;
}	t_vars;


// FUNCTIONS (SELON FILENAME)----------------------

// MINISHELL.C

// PARSING.C


//INIT_TOKEN.C
void	creating_tokens(char *line, t_vars *vars);
void	push_tk(char *cont, t_token *token, t_token *first, t_token *prev, int i, int count);
void	executing_command(char *line, t_vars *vars);
char	*defining_token_type(t_token *token);

//TOKEN_OP.C
void	debug_print_tokens(t_vars *vars);
void	*access_ptr(t_vars *vars, int i);

// ------------------------------------------------
#endif