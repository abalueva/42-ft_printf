# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:52:02 by abalueva          #+#    #+#              #
#    Updated: 2019/11/24 20:52:26 by abalueva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES =	help/additional_str.c help/additional.c \
			help/ft_ftoa.c help/ft_qtoa.c help/libft.c \
			ft_printf.c get_str.c specifier.c \
			print_cs.c print_upxxob.c print_di.c print_f.c
OBJECTS = 	additional_str.o additional.o \
			ft_ftoa.o ft_qtoa.o libft.o \
			ft_printf.o get_str.o specifier.o \
			print_cs.o print_upxxob.o print_di.o print_f.o \
			
NAME = libftprintf.a
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDE) -g
	ar rc $(NAME) *.o
	ranlib $(NAME)

.PHONY: all clean flcean re

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all