/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_larger_nbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:19:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/04 13:24:19 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	ft_smallest_larger_nbr(t_stack *stack, int nbr, int *smallest_larger)
{
	*smallest_larger = INT_MAX;
	while (stack)
	{
		if (stack->nbr > nbr && stack->nbr < *smallest_larger)
		{
			*smallest_larger = stack->nbr;
		}
		stack = stack->next;
	}
	if (*smallest_larger == INT_MAX)
		return ('x');
	else
		return ('y');
}

int	ft_smallest_nbr(t_stack *stack)
{
	int	smallest_larger;

	smallest_larger = INT_MAX;
	while (stack)
	{
		if (stack->nbr < smallest_larger)
		{
			smallest_larger = stack->nbr;
		}
		stack = stack->next;
	}
	return (smallest_larger);
}

t_stack	*get_min_nbr(t_stack *a)
{
	int		min;
	t_stack	*tmp;

	min = a->nbr;
	tmp = a;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (min == tmp->nbr)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*serach_and_return(t_stack *a, int nbr)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
