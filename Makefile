###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_minishell_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
NAME = minishell

SRCS_FILES 		=	minishell.c \
					parsing.c	\
					init_token.c \
					token_op.c
					
					
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
CURSOR_UP	= \033[0A
CURSOR_DOWN	= \033[0B

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
LEAK = leaks --atExit -- ./minishell
VALGRING = valgrind --track-fds=yes --track-origins=yes  --leak-check=full ./minishell
###--------------------------## REGLES ##--------------------------###

all: $(NAME)

$(NAME) : $(OBJS_IN_DIR)
	@echo "$(BLUE)Compiling $(NAME)...$(END)"
	@$(CC) $(CFLAGS) $(OBJS_IN_DIR) -lreadline $(LIBS) -o $(NAME)
	@echo "MINISHELL	| STATUS: \033[0;32mOK\033[0;00m"
	@echo "---------------------------------------------"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)Compiling object $< ..$(END)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@rm -rf $(OBJS_DIR)
	@echo "MINISHELL	| STATUS: \033[0;36m🛁OBJECTS CLEANED🛁\033[0;00m"

fclean:	clean
	@rm -rf $(NAME) $(BONUS)
	@echo "MINISHELL	| STATUS: \033[0;36m🚮EXECUTABLE CLEANED🚮\033[0;00m"

leak:
	$(LEAK)

valgrind:
	$(VALGRIND)

re:	fclean all 
	./$(NAME)

help:
	@echo "Rules: all clean fclean re"

