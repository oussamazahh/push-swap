/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:06:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/24 15:53:37 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void   display_stack(t_stack *stack)
{
    t_stack *tmp;
    int     i;

    tmp = stack;
    i = 0;
    while (tmp != NULL)
    {
        printf("[%d[%d]] => ",tmp->nbr, tmp->index);
        tmp = tmp->next;
        i++;
    }
	printf("[NULL]\n");
}

int	lst_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void    reset_index(t_stack **a, t_stack **b)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = *a;
    while (tmp)
    {
        tmp->index = i;
        i++;
        tmp = tmp->next;
    }
    i = 0;
    tmp = *b;
    while (tmp)
    {
        tmp->index = i;
        i++;
        tmp = tmp->next;
    }
}

int ft_calcule_moyen(t_stack *b, int size)
{
    int avg;
    int value;

    avg = 0;
    value = 0;
    while (b)
    {
        value += b->nbr;
        b = b->next;
    }
     if (size != 0)
        avg = value / size;
    return (avg);
}
