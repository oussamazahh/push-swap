# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:03:21 by ozahidi           #+#    #+#              #
#    Updated: 2024/04/27 15:38:30 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# -g -fsanitize=address
#  -fsanitize=address

NAME = push_swap

SRCS = mandatory/ft_moves.c mandatory/ft_push_swap.c mandatory/tools.c \
	mandatory/lst_tools.c mandatory/ft_operations.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} libft/libft.a ft_printf/libftprintf.a

%.o: %.c ft_push_swap.h
	${CC} -o $@ ${CFLAGS} $<

clean:
	make clean -C libft/
	make clean -C ft_printf/
	rm -rf ${OBJS}

fclean: clean
	make fclean -C libft/
	make fclean -C ft_printf/
	rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re