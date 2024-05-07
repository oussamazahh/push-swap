/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:35:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 15:21:28 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	free(*a);
	while (b && *b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(*b);
}

void	ft_exiit(void)
{
	ft_printf("Error\n");
	exit (2);
}
