# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:03:21 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/07 15:48:40 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 
# -g -fsanitize=address

NAME = push_swap

BONUS = checker

SRCS = $(addprefix mandatory/,ft_moves.c ft_push_swap.c  tools.c lst_tools.c\
							 tools1.c ft_operations.c ft_moves1.c ft_calucule_top.c\
							 ft_smallest_larger_nbr.c ft_best_match.c ft_calcule_moves.c\
							 ft_check.c ft_free.c ft_sort.c)

BSRC = $(addprefix bonus/,ft_moves_bonus.c ft_push_swap_bonus.c  tools_bonus.c lst_tools_bonus.c\
							 tools1_bonus.c ft_operations_bonus.c ft_moves1_bonus.c\
							 ft_free_bonus.c ft_instractions_bonus.c)

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRC:.c=.o}


%.o: %.c ft_push_swap.h ft_push_swap_bonus.h
	${CC} -o $@ ${CFLAGS} -c $<

all : ${NAME}

${NAME} : ${OBJS}
	@make -s -C Tools/
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} Tools/tools.a

bonus : ${BOBJS}
	@make -s -C Tools/
	${CC} ${CFLAGS} ${BOBJS} -o ${BONUS} Tools/tools.a
	
clean:
	@make -s clean -C Tools/
	rm -rf ${OBJS} ${BOBJS}

fclean: clean
	@make -s fclean -C Tools/
	rm -rf ${NAME} ${BONUS}

re: fclean all

.PHONY : all clean fclean re