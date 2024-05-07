/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calucule_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:48:34 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/02 14:53:06 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	help_calcule(t_stack **a_b, t_stack *tmp)
{
	while (tmp)
	{
		if (tmp->index <= (lst_size(*a_b) / 2))
			tmp->top = 1;
		else
			tmp->top = 0;
		tmp = tmp->next;
	}
}

void	ft_calucule_top(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = *a;
		help_calcule(a, tmp);
	}
	if (b)
	{
		tmp = *b;
		help_calcule(b, tmp);
	}
}
