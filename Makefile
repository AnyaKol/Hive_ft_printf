# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 15:29:34 by akolupae          #+#    #+#              #
#    Updated: 2025/05/20 21:20:34 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = libftprintf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	ft_printf.c \
	ft_printf_format.c \
	ft_printf_utils.c \

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_NAME)
	ar -rcs $(NAME) $(LIB_NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
