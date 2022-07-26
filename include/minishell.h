#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
#include <signal.h>

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
	int		ac; //use?
	char	**av; //use?
	char 	**env;
	char	*pwd;
	char	*oldpwd;
	t_token	*token;
}	t_vars;

// FUNCTIONS (SELON FILENAME)----------------------

// MINISHELL.C
void	init_shell(t_vars *vars, char **env);
// PARSING.C

// NEW_SPLIT.C
char	*unquoted_wrd_array(char *s, int *n);
char	*single_quoted_wrd_array(char *line, int *n);
char	*double_quoted_wrd_array(char *line, int *n);
char	**new_split(char *line);

// PARSING_UTILS.C
int	how_many_quotes(char *str);
int	len_of_this_word(char *line, int i);
int	len_single_quoted_word(char *line, int i);
int	len_double_quoted_word(char *line, int i);
int	nbr_of_words(char *s);
int	nbr_of_letters(char *s, int i, int code);

//INIT_TOKEN.C
void	creating_tokens(char *line, t_vars *vars);
void	push_tk(char *cont, t_token *token, t_token *first, t_token *prev, int i, int count);
void	executing_command(char *line, t_vars *vars, char **env);
char	*defining_token_type(t_token *token);

//TOKEN_OP.C
void	debug_print_tokens(t_vars *vars);
void	*access_ptr(t_vars *vars, int i);


//buit_ins
void	ft_pwd(t_vars *vars);
void	ft_env(t_vars *vars);
// void	ft_cd(char **env, t_vars vars);
// void	ft_echo(char **env);
// ------------------------------------------------
#endif