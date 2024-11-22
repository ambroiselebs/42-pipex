# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberenge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:49:03 by aberenge          #+#    #+#              #
#    Updated: 2024/10/23 18:09:08 by aberenge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/ft_printf.c src/ft_convert_fd.c src/ft_putchar_fd.c src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c src/ft_print_ptr.c
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

