/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:41:22 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/02 20:41:32 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_check_a(t_stack **a, t_stack **b, t_stack *check)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->nbr != check->nbr)
	{
		reset_index(a, b);
		ft_calucule_top(a, b);
		if (check->top == 1)
			rotate_a(a, b, "ra");
		else if (check->top == 0)
			reverse_rotate_a(a, b, "rra");
		tmp = *a;
	}
}

void	ft_check_b(t_stack **a, t_stack **b, t_stack *check)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp && tmp->nbr != check->nbr)
	{
		reset_index(a, b);
		ft_calucule_top(a, b);
		if (check->top == 1)
			rotate_b(a, b, "rb");
		else if (check->top == 0)
			reverse_rotate_b(a, b, "rrb");
		tmp = *b;
	}
}
