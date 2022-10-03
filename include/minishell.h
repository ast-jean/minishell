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
	char	**av; //params for execve
	char 	**env;
	// char	**cmd_line;
	char	*path;
	char	**path_array;
	int		heredoc_count;
	char	*pwd;
	char	*oldpwd;
	char	*line;
	t_token	*token;
	int		pipe_count;
	int		pid[32768];
	int		pid_count;
	int		status;
	char 	*cd_oldpwd;
}	t_vars;

typedef struct s_hds
{
	int		init;
	int		in_heredoc;
	int		end;
	t_vars	*vars;
} t_hds;



// pid = hd_function()->pid;


// FUNCTIONS (SELON FILENAME)----------------------

// NOTE: EXECUTION

// MINISHELL.C
void	init_shell(t_vars *vars, char **env);
void	handler(int sig);
// int		is_builtin(t_token *current, t_vars *vars, char **env);
t_hds	*f_hds();

// EXECUTION_CMD.C
void	finding_paths(t_vars *vars);
int		accessing(t_vars *vars, t_token *token);
void	executing_simple_cmds(t_vars *vars, t_token *token);

// HEREDOCS.c
int		check_here(t_vars *vars);
char	*remove_quotes(char *str);

//SYNTAX_ERROR.c
int		syntax_error(char *token);
int		is_exception(t_token *token);
int		check_quotes(char *str);

// VARIABLES.c
char 	*check_var(char *line);
char 	*check_var_heredoc(char *line, t_vars *vars);
char	*add_varcontent(char *line, char *var_name, char *var_value);
char	*ft_getenv(char **env, char *varname);


//QUIT.C
void	quit_shell(t_vars *vars);
void	free_tokens(t_vars *vars);
void	free2d(char **split);

// PIPES.C
int		is_builtin(t_token *current, t_vars *vars, char **env, int fdi);
void	fd_catch(t_vars *vars, t_token *current, char **env);
t_token	*group_skip(t_token *current_token);

// SET_GROUPS.C
int		init_groups(t_vars *vars);
int		parsing_pipes(t_vars *vars);

//	REDIRECTION.C
int		redirect_input(t_token *token, int fd_init);
int		redirect_output(t_token *token, int fd_init);
t_token *rm_redir(t_token *token, t_vars *vars);

//NOTE: PARSING
// PARSING_UTILS.C
int		how_many_quotes(char *str);
int		len_of_this_word(char *line, int i);
int		len_single_quoted_word(char *line, int i);
int		len_double_quoted_word(char *line, int i);
int		nbr_of_words(char *s);
int		nbr_of_letters(char *s, int i, int code);

//INIT_TOKEN.C
int		creating_tokens(char *line, t_vars *vars);
void	push_tk(char *cont, t_token *token, t_token *first, t_token *prev, int i, int count);
void	executing_command(char *line, t_vars *vars, char **env);

//TOKEN_OP.C
void	debug_print_tokens(t_vars *vars); //temp_function
void	*access_ptr(t_vars *vars, int i);
t_token	*new_token_after(t_token *after_this_one, char* file_name);
t_token *remove_token(t_token *remove, t_vars *vars);

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
int	builtin_pwd(t_vars *vars);
int	builtin_env(t_vars *vars);
// EXPORT_UNSET.C
int	builtin_unset(t_vars *vars, char *var_name);
int	builtin_export(t_token *token, t_vars *vars);
// ECHO_CD.C
int	builtin_echo(t_vars *vars);
// CD.c
int	builtin_cd(t_vars *vars, char **env);
//NOTE: ------------------------------------------------
#endif
