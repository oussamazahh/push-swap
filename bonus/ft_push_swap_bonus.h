/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:56 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 16:10:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include "../Tools/ft_tools.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				top;
	int				best_match;
	int				moves;
	int				all_moves;
	int				best_move;
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back(t_stack **stack, t_stack *new);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack				*ft_lstnew(int nb, int i);
int					lst_size(t_stack *stack);
void				reset_index(t_stack **a, t_stack **b);
int					order_stack(t_stack *a);
void				_create_tab(char **all, t_stack **a, t_stack **b, int i);
void				_create_stack(t_stack **a, t_stack **b, int *tab, int i);
int					len_double_p(char **double_all);
void				sort_stack(t_stack **a, t_stack **b);
void				_instractions(t_stack **a, t_stack **b);
void				ft_exiit(void);
//moves
void				swap_a(t_stack **a, t_stack **b);
void				swap_b(t_stack **a, t_stack **b);
void				swap_a_b(t_stack **a, t_stack **b);
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				rotate_a(t_stack **a, t_stack **b);
void				rotate_b(t_stack **a, t_stack **b);
void				rotate_a_b(t_stack **a, t_stack **b);
void				reverse_rotate_a(t_stack **a, t_stack **b);
void				reverse_rotate_b(t_stack **a, t_stack **b);
void				reverse_rotate_a_b(t_stack **a, t_stack **b);

//algo

void				order_in3(t_stack **a, t_stack **b); //srot 3
void				push_swap(t_stack **a, t_stack **b);
void				ft_calucule_top(t_stack **a, t_stack **b);
long long			ft_calcule_moyen(t_stack *b, int size); //moyen
int					small_stack(t_stack *a);
int					ft_smallest_nbr(t_stack *stack);
char				ft_smallest_larger_nbr(t_stack *stack, int nbr,
						int *smallest_larger);
void				ft_best_match(t_stack **a, t_stack **b);
void				ft_calcule_moves(t_stack **a, t_stack **b);
void				ft_calucule_all_moves(t_stack **a, t_stack **b);
void				ft_best_move(t_stack **a, t_stack **b);
int					ft_get_moves(t_stack *a, int best_match);
t_stack				*get_min_nbr(t_stack *a);
void				ft_check_a(t_stack **a, t_stack **b, t_stack *check);
void				ft_check_b(t_stack **a, t_stack **b, t_stack *check);
t_stack				*serach_and_return(t_stack *a, int nbr);
void				ft_free(char **all);
void				ft_free_stack(t_stack **a, t_stack **b);
int					check_numbers(int *tab, int a);
#endif