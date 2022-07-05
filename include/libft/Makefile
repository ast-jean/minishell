# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 16:04:57 by ast-jean          #+#    #+#              #
#    Updated: 2022/06/08 12:26:03 by ast-jean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c	\
	  ft_bzero.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strrchr.c \
	  ft_strchr.c \
	  ft_strlen.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_powerof.c \
	  get_next_line.c \
	  ft_get_file.c

OBJ_DIR = obj/

HEADER =-I  libft.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

SRC_IN_DIR = $(addprefix $(SRC_DIR), $(SRC))
OBJ_IN_DIR = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_B_IN_DIR = $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling ... $<"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

bonus: $(OBJ) $(OBJ_B_IN_DIR)
	@ar rcs $(NAME) $^
	@echo "Libft bonuses completed"

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@mv *.o $(OBJ_DIR)
	@echo "Libft completed"

clean:
	@rm -f *.o
	@echo "objects deleted"

fclean: clean
	@rm -f libft.a
	@rm -rf obj
	@echo "Objects directory and libft.a deleted"

re: fclean all

.PHONY:
	@all bonus clean fclean re
