/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:02:12 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/04 21:07:46 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (order_stack(*a) == 1 && lst_size(*a) != 1)
	{
		if (lst_size(*a) == 2)
			rotate_a(a, NULL, "ra");
		if (lst_size(*a) == 3)
			order_in3(a, b);
		if (lst_size(*a) > 3)
			push_swap(a, b);
	}
}
