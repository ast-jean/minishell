#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

// STRUCTS
typedef struct s_token
{
	int				group_num;
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
	int		heredoc_count;
	char	*pwd;
	char	*oldpwd;
	t_token	*token;
	int		pipe_count;
}	t_vars;

// FUNCTIONS (SELON FILENAME)----------------------

// NOTE: EXECUTION
// MINISHELL.C
void	init_shell(t_vars *vars, char **env);
void	handler(int sig);

// EXECUTION_CMD.C
void	finding_paths(t_vars *vars);
int		accessing(t_vars *vars, t_token *token);
void	executing_simple_cmds(t_vars *vars, t_token *token);

// HEREDOCS.c
int	check_heredocs(t_vars *vars);

//QUIT.C
void	quit_shell(t_vars *vars);
void	free_tokens(t_vars *vars);

// PIPES.C

// SET_GORUPS.C
int	init_groups(t_vars *vars);

//NOTE: PARSING
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
void	debug_print_tokens(t_vars *vars); //temp_function
void	*access_ptr(t_vars *vars, int i);
t_token	*new_token_after(t_token *after_this_one, char* file_name);
t_token	*remove_token(t_token *remove);

//NEWTOKEN.C
char	*newtoken_q(char *line, int *i, char c);
char	*newtoken_s(char *line, int *i);
char	*newtoken_d(char *line, char *delims, int i, int j);
void	increm(int *i, int *j);

//TOKENIZE.C
char	**tokenize(char *line);
char	**nullify_str(char *line, char *delims, int len, int count);
int		cnt_delims(char *line, char *delims);

//NOTE: BUILT INS
// PWD_ENV.C
void	builtin_pwd(t_vars *vars);
void	builtin_env(t_vars *vars);
// EXPORT_UNSET.C
void	builtin_unset(t_vars *vars, char *var_name);
void	builtin_export(t_token *token, t_vars *vars);
// ECHO_CD.C
//// void	builtin_cd(char **env, t_vars vars);
void	builtin_echo(char **args, char **env);

//NOTE: ------------------------------------------------
#endif
