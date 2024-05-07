/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:12 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 18:40:07 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	swap_a(t_stack **a, t_stack **b)
{
	int	tmp;

	(void)b;
	if (!a || !*a || lst_size(*a) == 1)
		return ;
	tmp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = tmp;
}

void	swap_b(t_stack **a, t_stack **b)
{
	int	tmp;

	(void)a;
	if (!b || !*b || lst_size(*b) == 1)
		return ;
	tmp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = tmp;
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap_a(a, b);
	swap_b(a, b);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
