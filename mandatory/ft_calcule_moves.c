/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcule_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:24:35 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/04 13:05:50 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_calcule_moves(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)a;
	tmp = *b;
	while (tmp)
	{
		if (tmp->top == 1)
			tmp->moves = tmp->index;
		if (tmp->top == 0)
			tmp->moves = lst_size(*b) - tmp->index;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->top == 1)
			tmp->moves = tmp->index;
		if (tmp->top == 0)
			tmp->moves = lst_size(*a) - tmp->index;
		tmp = tmp->next;
	}
}

int	ft_get_moves(t_stack *a, int best_match)
{
	while (a)
	{
		if (a->nbr == best_match)
			return (a->moves);
		a = a->next;
	}
	return (-1);
}

void	ft_calucule_all_moves(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)a;
	tmp = *b;
	while (tmp)
	{
		tmp->all_moves = tmp->moves + ft_get_moves(*a, tmp->best_match);
		tmp = tmp->next;
	}
}

void	ft_best_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;

	(void)a;
	min = INT_MAX;
	tmp = *b;
	while (tmp)
	{
		if (min > tmp->all_moves)
			min = tmp->all_moves;
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp)
	{
		if (min == tmp->all_moves)
			tmp->best_move = 1;
		else
			tmp->best_move = 0;
		tmp = tmp->next;
	}
}
