/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:56 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 15:10:22 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

typedef struct s_stack
{
	int			    nbr;
	int			    index;
	int				top;
	int				best_match;
	int				moves;
	int				all_moves;
	int				best_move;
	struct s_stack	*next;
}t_stack;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstnew(int nb, int i);
void    del_first(t_stack **stack);
t_stack	*ft_lstlast(t_stack *lst);
void    del_last(t_stack **stack);
int		lst_size(t_stack *stack);
void    reset_index(t_stack **a, t_stack **b);
int order_stack(t_stack *a);

void   display_stack(t_stack *stack);
void   display_stack2(t_stack *stack);
//moves
void	swap_a(t_stack **a, t_stack **b, char *str);
void    swap_b(t_stack **a, t_stack **b, char *str);
void    swap_a_b(t_stack **a, t_stack **b, char *str);
void    push_a(t_stack **a, t_stack **b, char *str);
void    push_b(t_stack **a, t_stack **b, char *str);
void    rotate_a(t_stack **a, t_stack **b, char *str);
void    rotate_b(t_stack **a, t_stack **b, char *str);
void    rotate_a_b(t_stack **a, t_stack **b, char *str);
void    reverse_rotate_a(t_stack **a, t_stack **b, char *str);
void    reverse_rotate_b(t_stack **a, t_stack **b, char *str);
void    reverse_rotate_a_b(t_stack **a, t_stack **b, char *str);

//algo
void order_in3(t_stack **a, t_stack **b);//srot 3
void    push_swap(t_stack **a, t_stack **b);
long long ft_calcule_moyen(t_stack *b, int size);//moyen
int small_stack(t_stack *a);

#endif