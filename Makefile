# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:03:21 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/06 14:42:53 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=address
#  -fsanitize=address

NAME = push_swap

BONUS = checker

# SRCS = mandatory/ft_moves.c mandatory/ft_push_swap.c mandatory/tools.c \
# 	mandatory/lst_tools.c mandatory/tools1.c mandatory/ft_operations.c \
# 	mandatory/ft_moves1.c mandatory/ft_calucule_top.c mandatory/ft_smallest_larger_nbr.c \
# 	mandatory/ft_best_match.c mandatory/ft_calcule_moves.c mandatory/ft_check.c \
# 	mandatory/ft_free.c mandatory/ft_sort.c

SRCS = $(addprefix mandatory/,ft_moves.c ft_push_swap.c  tools.c lst_tools.c\
							 tools1.c ft_operations.c ft_moves1.c ft_calucule_top.c\
							 ft_smallest_larger_nbr.c ft_best_match.c ft_calcule_moves.c\
							 ft_check.c ft_free.c ft_sort.c)

BSRC = $(addprefix bonus/,ft_moves_bonus.c ft_push_swap_bonus.c  tools_bonus.c lst_tools_bonus.c\
							 tools1_bonus.c ft_operations_bonus.c ft_moves1_bonus.c\
							 ft_free_bonus.c ft_instractions.c)

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRC:.c=.o}


%.o: %.c ft_push_swap.h
	@${CC} -o $@ ${CFLAGS} -c $<

all : ${NAME}

${NAME} : ${OBJS}
	@make -s -C Tools/
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} Tools/tools.a

bonus : ${BOBJS}
	@make -s -C Tools/
	@${CC} ${CFLAGS} ${BOBJS} -o ${BONUS} Tools/tools.a
	
clean:
	@make -s clean -C Tools/
	@rm -rf ${OBJS} ${BOBJS}

fclean: clean
	@make -s fclean -C Tools/
	@rm -rf ${NAME} ${BONUS}

re: fclean all

.PHONY : all clean fclean re