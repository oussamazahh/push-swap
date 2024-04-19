# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:03:21 by ozahidi           #+#    #+#              #
#    Updated: 2024/04/16 19:49:45 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror
#  -fsanitize=address

NAME = push_swap

SRCS = mandatory/ft_moves.c mandatory/ft_push_swap.c mandatory/tools.c \
	mandatory/lst_tools.c

OBJS = ${SRCS:.c=.o}

# %.o: %.c ft_push_swap.h
# 	${CC} -o $@ ${CFLAGS} $<

all : ${NAME}

${NAME} :
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} libft/libft.a ft_printf/libftprintf.a

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