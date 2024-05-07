/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:21:50 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/04 12:52:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_best_match(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		smallest_larger;

	tmp = *a;
	tmp1 = *b;
	while (tmp1)
	{
		if (ft_smallest_larger_nbr(*a, tmp1->nbr, &smallest_larger) == 'x')
			smallest_larger = ft_smallest_nbr(*a);
		while (tmp)
		{
			if (tmp->nbr == smallest_larger)
				tmp1->best_match = tmp->nbr;
			tmp = tmp->next;
		}
		tmp = *a;
		tmp1 = tmp1->next;
	}
}
