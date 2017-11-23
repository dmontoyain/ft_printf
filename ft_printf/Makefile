#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 20:24:48 by dmontoya          #+#    #+#              #
#    Updated: 2017/11/22 14:30:25 by dmontoya         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FUNCTIONS = ft_printf \
			types_handler \
			flags \
			types_handler_a \
			types_handler_b \
			utilities \
			mod_handler \
			num_utilities \
			types_handler_c

LIBFTFUNCTIONS = ft_putnbr \
				ft_putchar \
				ft_strdel \
				ft_strdup \
				ft_wcharlen \
				ft_wcstrlen \
				ft_strnew \
				ft_strlen \
				ft_itoa \
				ft_atoi \
				ft_isdigit

C_FILES = $(addsuffix .c, $(FUNCTIONS))
LIBC_FILES = $(addsuffix .c, $(LIBFTFUNCTIONS))
LIBOBJ_FILES = $(addsuffix .o, $(LIBFTFUNCTIONS))
OBJ_FILES = $(addsuffix .o, $(FUNCTIONS))
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCL = libft/

all: $(NAME)

$(PFOBJ):
	$(CC) $(FLAGS) -c $(C_FILES)

$(LIBOBJ):
	$(CC) $(FLAGS) -c $(INCL)$(LIBC_FILES)

$(NAME): $(PFOBJ) $(LIBOBJ)
	ar rc $(NAME) $(OBJ_FILES) $(LIBOBJ_FILES)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_FILES) $(INCL)$(LIBOBJ_FILES)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re: fclean all

