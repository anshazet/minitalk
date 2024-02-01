# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 15:29:24 by ashalagi          #+#    #+#              #
#    Updated: 2023/03/13 11:14:35 by ashalagi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_string.c \
	ft_type_di.c \
	ft_type_p.c \
	ft_type_u.c \
	ft_type_x.c
CC = gcc

AR = ar rcs

FLAG = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
