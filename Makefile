#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 20:24:48 by dmontoya          #+#    #+#              #
#    Updated: 2017/11/25 23:39:33 by dmontoya         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FUNCTIONS = ft_printf \
			types_handler \
			flags \
			types_handler_a \
			types_handler_b \
			flag_utilities \
			mod_handler \
			num_utilities \
			types_handler_c \
			widthflag

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
				ft_isdigit \
				ft_putstr \
				ft_memset \
				ft_strsub \
				ft_strjoin \
				ft_itoa_base \
				ft_uitoa_base \
				ft_str_touppercase \
				ft_strdup

INCL = -I $(LIB)libft.h -I libftprintf.h
LIB = libft/
C_FILES = $(addsuffix .c, $(FUNCTIONS))
LIBC_FILES = $(addsuffix .c, $(LIBFTFUNCTIONS))
LIBOBJ_FILES = $(LIBC_FILES:.c=.o)
OBJ_FILES = $(addsuffix .o, $(FUNCTIONS))
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(PFOBJ) $(LIBOBJ) $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(INCL) -c $(C_FILES) $(addprefix $(LIB), $(LIBC_FILES))
	ar rcs $(NAME) $(OBJ_FILES) $(LIBOBJ_FILES)

clean:
	rm -rf $(OBJ_FILES) $(LIBOBJ_FILES)

fclean:	clean
	rm -f $(NAME)

re: fclean all

