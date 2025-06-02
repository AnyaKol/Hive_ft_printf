# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 15:29:34 by akolupae          #+#    #+#              #
#    Updated: 2025/06/02 13:29:52 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h
HDR_B = ft_printf_bonus.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	ft_printf.c \
	ft_printf_flags.c \
	ft_printf_format.c \
	ft_printf_precision.c \
	ft_printf_utils.c \

SRC_B = \
	ft_printf_bonus.c \
	ft_printf_flags_bonus.c \
	ft_printf_format_bonus.c \
	ft_printf_precision_bonus.c \
	ft_printf_utils_bonus.c \

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
LIB_HDR = $(LIB_DIR)/libft.h

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR) $(LIB_NAME)
	cp $(LIB_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJ)

bonus: fclean $(OBJ_B) $(HDR_B) $(LIB_NAME)
	cp $(LIB_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJ_B)

$(LIB_NAME): $(LIB_HDR)
	$(MAKE) -C $(LIB_DIR)

%.o: %.c $(LIB_HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ) $(OBJ_B)
.PHONY: all clean fclean re bonus
