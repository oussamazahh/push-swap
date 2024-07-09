/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:14 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 17:38:07 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	rotate_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!a || !*a || lst_size(*a) == 1)
		return ;
	(void)b;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	tmp1 = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	*a = tmp1;
}

void	rotate_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!b || !*b || lst_size(*b) == 1)
		return ;
	(void)a;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	tmp1 = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = tmp;
	*b = tmp1;
}

void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}

void	reverse_rotate_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!a || !*a || lst_size(*a) == 1)
		return ;
	(void)b;
	tmp1 = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	tmp1->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void	reverse_rotate_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!b || !*b || lst_size(*b) == 1)
		return ;
	(void)a;
	tmp1 = *b;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	tmp1->next = NULL;
	tmp->next = *b;
	*b = tmp;
}
