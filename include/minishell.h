#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
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

// NEW_SPLIT.C
char	*unquoted_wrd_array(char *s, int *n);
char	*quoted_wrd_array(char *line, int *n);
char	**new_split(char *line);

// PARSING_UTILS.C
int	how_many_quotes(char *str);
int	len_of_this_word(char *line, int i);
int	len_of_this_quoted_word(char *line, int i);
int	nbr_of_words(char const *s);


//INIT_TOKEN.C
void	*creating_tokens(char *line, t_vars *vars);


// ------------------------------------------------
#endif