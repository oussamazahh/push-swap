/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:11:31 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/02 20:55:40 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate_a_b(t_stack **a, t_stack **b, char *str)
{
	reverse_rotate_a(a, b, "x");
	reverse_rotate_b(a, b, "x");
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	move_to_up(t_stack **a, t_stack **b, t_stack *this, t_stack *tmp)
{
	if (tmp->top == 1 && this->top == 1)
	{
		while ((*a)->nbr != this->nbr && (*b)->nbr != tmp->nbr)
			rotate_a_b(a, b, "rr");
	}
	else if (tmp->top == 0 && this->top == 0)
	{
		while ((*a)->nbr != this->nbr && (*b)->nbr != tmp->nbr)
			reverse_rotate_a_b(a, b, "rrr");
	}
}

void	ft_move_to_first(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*this;

	tmp = *b;
	while (tmp)
	{
		if (tmp->best_move == 1)
		{
			reset_index(a, b);
			ft_calucule_top(a, b);
			this = serach_and_return(*a, tmp->best_match);
			move_to_up(a, b, this, tmp);
			ft_check_a(a, b, this);
			ft_check_b(a, b, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

static void	operations_room(t_stack **a, t_stack **b)
{
	reset_index(a, b);
	order_in3(a, b);
	while (lst_size(*b))
	{
		ft_calucule_top(a, b);
		ft_best_match(a, b);
		ft_calcule_moves(a, b);
		ft_calucule_all_moves(a, b);
		ft_best_move(a, b);
		ft_move_to_first(a, b);
		push_a(a, b, "pa");
		reset_index(a, b);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (*a && lst_size(*a) > 3)
	{
		ft_calucule_top(a, b);
		if ((*a)->nbr < (int)ft_calcule_moyen(*a, lst_size(*a)))
			push_b(a, b, "pb");
		else
			rotate_a(a, b, "ra");
	}
	operations_room(a, b);
	min = get_min_nbr(*a);
	reset_index(a, b);
	ft_calucule_top(a, b);
	if (min->top)
	{
		while ((*a)->nbr != min->nbr)
			rotate_a(a, b, "ra");
	}
	else
	{
		while ((*a)->nbr != min->nbr)
			reverse_rotate_a(a, b, "rra");
	}
}
