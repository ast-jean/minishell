###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_minishell_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
NAME = minishell

SRCS_FILES 		=	parsing/parsing.c			\
					parsing/new_split.c			\
					parsing/new_split_utils.c	\
					# parsing/init_token.c		\

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
CURSOR_UP_1	= \033[1A
CURSOR_UP	= \033[2A
CURSOR_DOWN	= \033[1B

END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m

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
# @echo "                                        "
	@echo "$(CURSOR_UP_1)$(SELECTED)MINISHELL$(END)                                     "
	@echo "$(GREEN)Compiling DONE!                                  $(END)"
	@echo "$(BLUE)Executable $(NAME) created                 $(END)"
	@$(CC) $(CFLAGS) $(OBJS_IN_DIR) -lreadline $(LIBS) -o $(NAME)
	@echo "MINISHELL       | STATUS: $(GREEN)OK$(END)       "
	@echo "----------------------------"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(MAKE) -C include/libft
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/execution
	@mkdir -p $(OBJS_DIR)/built_ins
	@echo "$(CURSOR_UP)Compiling $< ..           "
	@$(CC) $(CFLAGS) -c $< -o $@

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

help:
	@echo "Rules: all clean fclean re"

