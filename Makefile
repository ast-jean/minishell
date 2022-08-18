###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_minishell_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
NAME = minishell

SRCS_FILES 		=	execution/minishell.c		\
					execution/execution.c		\
					parsing/parsing.c			\
					parsing/new_split.c			\
					parsing/new_split_utils.c	\
					parsing/new_split_utils2.c	\
					parsing/init_token.c		\
					parsing/token_op.c			\
					built_ins/export.c			\
					built_ins/built_in.c		\
					built_ins/echo_cd.c			\

INCLUDE_FILES	= 	minishell.h

LIBS = include/libft/libft.a
READLINE = -lreadline -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

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

### Compilations et archivage ###
CC 			= gcc
CFLAGS 		= -g -Wall -Wextra -Werror 
### Autres Fonctions ###
NORMINETTE 	= norminette
###------------------------## LEAK CHECK ##------------------------###
LEAK = leaks -q --atExit -- ./minishell
VALGRING = valgrind --track-fds=yes --track-origins=yes  --leak-check=full ./minishell
###--------------------------## REGLES ##--------------------------###
all: $(NAME)

$(NAME) : $(OBJS_IN_DIR)
	@echo "$(CURSOR_UP_1)$(SELECTED)MINISHELL$(END)                                     "
	@echo "$(GREEN)Compiling DONE! ✅                                 $(END)"
	@$(CC) $(CFLAGS) $(OBJS_IN_DIR) $(LIBS) $(READLINE) -o $@ 
	@echo "$(BLUE)Executable $(NAME) created                 $(END)"
	@echo "----------------------------"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(MAKE) -C include/libft
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/execution
	@mkdir -p $(OBJS_DIR)/built_ins
	@echo "$(CURSOR_UP)Compiling $< ..           "
	@$(CC) -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include  $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C include/libft clean
	@rm -f *.o
	@rm -rf $(OBJS_DIR)
	@echo "MINISHELL	| STATUS: $(CYAN)OBJECTS CLEANED$(END)"

fclean:	clean
	@$(MAKE) -C include/libft fclean
	@rm -rf $(NAME)
	@echo "MINISHELL	| STATUS: $(BLUE)EXECUTABLE CLEANED$(END)"

leak:
	$(LEAK)

valgrind:
	$(VALGRIND)

re:	fclean all 
	./$(NAME)

rew: 
	@echo " "
	@rm -rf $(NAME)
	@rm -f *.o
	@rm -rf $(OBJS_DIR)
	@$(MAKE) $(NAME)
	./$(NAME)

help:
	@echo "Rules: all clean fclean re"

