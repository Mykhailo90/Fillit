#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 13:57:13 by msarapii          #+#    #+#              #
#    Updated: 2017/11/24 17:04:35 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=fillit
SRCS=main.c ft_putchar.c ft_putstr.c read_list.c ft_memalloc.c ft_bzero.c check_type_symbols.c ft_strsplit.c ft_strncpy.c check_valid_terminos.c count_tetriminos.c check_form.c
OBJ=main.o ft_putchar.o ft_putstr.o read_list.o ft_memalloc.o ft_bzero.o check_type_symbols.o ft_strsplit.o ft_strncpy.o check_valid_terminos.o count_tetriminos.o check_form.o
HEADERS=./funclib.h

all: $(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)
			$(CC) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)

fclean: 
	rm -rf $(NAME) $(OBJ)

re: fclean all
