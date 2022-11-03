###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_minishell_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
NAME = minishell

SRCS_FILES 		=	built_ins/cd_pwd.c					\
					built_ins/unset_export_env.c		\
					built_ins/echo.c					\
					execution/check_heredoc.c			\
					execution/exec_simp_cmd.c			\
					execution/heredocs.c 				\
					execution/minishell.c				\
					execution/main.c					\
					execution/pipes.c					\
					execution/pipes_util.c				\
					execution/quit.c					\
					execution/redirection.c				\
					execution/set_groups.c 				\
					execution/syntax_error.c			\
					execution/variables.c 				\
					parsing/init_token.c				\
					parsing/newtoken.c					\
					parsing/token_op.c					\
					parsing/tokenize.c					\
					parsing/token_util.c				\

INCLUDE_FILES	= 	minishell.h

LIBS = include/libft/libft.a

### Repertoires ###
SRCS_DIR 	= srcs/
OBJS_DIR	= objs/
INCLUDE_DIR = include/

## Naming files ##
OBJS 		= $(SRCS_FILES:.c=.o)
OBJS_IN_DIR	= $(addprefix $(OBJS_DIR), $(OBJS))
SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
INCLUDE 	= $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))

### Colour var ###
CLEAR_LINE		= \033[2K
CURSOR_UP_1		= \033[1A
CURSOR_UP		= \033[2A
CURSOR_DOWN		= \033[1B
CURSOR_FORWARD	= \033[1C
CURSOR_BACK  	= \033[1D

END				= \033[0m
BOLD			= \033[1m
ITALIC			= \033[3m
URL				= \033[4m
BLINK			= \033[5m
BLINK2			= \033[6m
SELECTED		= \033[7m

BLACK			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
VIOLET			= \033[35m
CYAN			= \033[36m
WHITE			= \033[37m

READLINE = -lreadline -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
### Compilations et archivage ###
CC 			= gcc
CFLAGS 		= -g -Wall -Wextra -Werror 
### Autres Fonctions ###
NORMINETTE 	= norminette
###------------------------## LEAK CHECK ##------------------------###
#LEAK = leaks -q --atExit -- ./minishell
#VALGRING = valgrind --track-fds=yes --track-origins=yes  --leak-check=full ./minishell
###--------------------------## REGLES ##--------------------------###
all: $(NAME)

$(NAME) : libft $(OBJS_IN_DIR)
	@echo "$(CURSOR_UP_1)$(CLEAR_LINE)$(GREEN)Compiling DONE! ✅$(END)"
	@$(CC) $(CFLAGS) $(OBJS_IN_DIR) $(LIBS) $(READLINE) -o $@ 
	@echo "$(BLUE)$(CLEAR_LINE)Executable $(NAME) created$(END)"
	@echo "----------------------------"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
# @echo "$(CLEAR_LINE)$(SELECTED)MINISHELL$(END)"
	@echo "$(CURSOR_UP_1)$(CLEAR_LINE)Compiling $<"
	@$(CC) -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include $(CFLAGS) -c $< -o $@


libft:
	@mkdir -p .tmp
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/execution
	@mkdir -p $(OBJS_DIR)/built_ins
	@$(MAKE) -sC include/libft
	@echo "$(CURSOR_UP)$(CLEAR_LINE)$(SELECTED)MINISHELL$(END)"
	@echo " "
clean:
	@$(MAKE) -sC include/libft clean
	@rm -f *.o
	@rm -rf $(OBJS_DIR)
	@echo "MINISHELL	| $(CYAN)OBJECTS CLEANED$(END)"

fclean:	clean
	@$(MAKE) -sC include/libft fclean
	@rm -rf $(NAME)
	@echo "MINISHELL	| $(BLUE)EXECUTABLE CLEANED$(END)"

# leak:
# 	$(LEAK)

valgrind: $(NAME)
	valgrind --suppressions=ignore_rdl_leaks.txt --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./minishell
	# valgrind --suppressions=ignore_rdl_leaks.txt --leak-check=full --trace-children=yes --track-fds=yes ./minishell
	
re:	fclean all 
	./$(NAME)

rew: 
	@echo " "
	@echo " "
	@rm -rf $(NAME)
	@rm -f *.o
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -s $(NAME)
	./$(NAME)

help:
	@echo "Rules: all clean fclean re"

