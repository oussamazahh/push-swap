/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:35:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 11:30:53 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_free(char **all)
{
	int	i;

	i = 0;
	if (all)
	{
		while (all[i])
		{
			free(all[i]);
			i++;
		}
		free(all);
	}
}

void	ft_free_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
		free(*a);
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
		free(*b);
	}
}
