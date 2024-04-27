/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:06:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 15:11:37 by ozahidi          ###   ########.fr       */
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
        ft_printf("[nbr %d[index %d](top %d)] target (%d) bestmove(%d)=> \n",tmp->nbr, tmp->index, tmp->top, tmp->best_match, tmp->best_move);
        tmp = tmp->next;
        i++;
    }
	printf("[NULL]\n");
}
void   display_stack2(t_stack *stack)
{
    t_stack *tmp;
    int     i;

    tmp = stack;
    i = 0;
    while (tmp != NULL)
    {
        ft_printf("[nbr %d \n",tmp->nbr);
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
    if (a && *a)
    {
        tmp = *a;
        while (tmp)
        {
            tmp->index = i;
            i++;
            tmp = tmp->next;
        }
        
    }
    i = 0;
    if (b && *b)
    {
        tmp = *b;
        while (tmp)
        {
            tmp->index = i;
            i++;
            tmp = tmp->next;
        }
        
    }
}

long long ft_calcule_moyen(t_stack *b, int size)
{
    int avg;
    long long value;

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
static int index_of_big(t_stack *a)
{
    t_stack *tmp;
    int     big;
    int     index;

    tmp = a;
    big = a->nbr;
    index = 0;
    while (tmp)
    {
        if (big < tmp->nbr)
            big =  tmp->nbr;
        tmp = tmp->next;
    }
    tmp = a;
    while (tmp)
    {
        if (big == tmp->nbr)
            index = tmp->index;
        tmp = tmp->next;
    }
    return (index);
}

void order_in3(t_stack **a, t_stack **b)
{
    int     index;
    (void )b;
    index = index_of_big(*a);
    if (index == 0)
    {
        rotate_a (a, b, "ra");
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
    if (index == 1)
    {
        reverse_rotate_a(a, b, "rra");
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
    if (index == 2)
    {
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
}

int small_stack(t_stack *a)
{
    t_stack *tmp;
    int     big;

    tmp = a;
    big = a->nbr;
    while (tmp)
    {
        if (big > tmp->nbr)
            big =  tmp->nbr;
        tmp = tmp->next;
    }
    return (big);
}

int order_stack(t_stack *a)
{
    int nb;

    nb = a->nbr;
    while (a)
    {
        if (nb > a->nbr)
            return (1);
        nb = a->nbr;
        a = a->next;
    }
    return (0);
}
