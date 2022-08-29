#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

// STRUCTS
typedef struct s_token
{
	char			*cont;
	struct s_token	*next;
	struct s_token	*prev;
	struct s_token	*first;
}	t_token;

typedef struct s_vars
{
	int		ac; //use?
	char	**av; //use?
	char 	**env;
	// char	**cmd_line;
	char	*path;
	char	**path_array;
	char	*pwd;
	char	*oldpwd;
	t_token	*token;
}	t_vars;

// FUNCTIONS (SELON FILENAME)----------------------

// MINISHELL.C
void	init_shell(t_vars *vars, char **env);
void	handler(int sig);

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
void	executing_command(char *line, t_vars *vars);

//TOKEN_OP.C
void	debug_print_tokens(t_vars *vars);
void	*access_ptr(t_vars *vars, int i);

//buit_ins
void	ft_pwd(t_vars *vars);
void	ft_env(t_vars *vars);
// void	ft_cd(char **env, t_vars vars);
// void	ft_echo(char **env);

// EXECUTION_CMD.C
void	finding_paths(t_vars *vars);
int		accessing(t_vars *vars, t_token *token);
void	executing_simple_cmds(t_vars *vars, t_token *token);
//QUIT.C
void	quit_shell(t_vars *vars);
void	free_tokens(t_vars *vars);

//export.c
void	ft_unset(t_vars *vars, char *var_name);
void	ft_export(t_token *token, t_vars *vars);

//heredocs.c
void	check_heredocs(t_vars *vars);
t_token	*new_token_after(t_token *after_this_one, char* file_name);
t_token	*remove_token(t_token *remove);
// ------------------------------------------------
#endif
