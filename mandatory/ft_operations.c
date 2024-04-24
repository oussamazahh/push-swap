/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:11:31 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/24 15:53:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    push_swap(t_stack **a, t_stack **b)
{
    int avg;
    t_stack *tmp;

    avg = 0;
    (void) b;
    tmp = *a;
    while (tmp && lst_size(*a) > 3)
    {
        if (lst_size(*a) > 3 &&  tmp->nbr < ft_calcule_moyen(*a, lst_size(*a)))
        {
            push_b(a, b, "pb");
            tmp = *a;
        }
        tmp = tmp->next;
    }
    ft_printf("stack a\n");
    display_stack(*a);
    ft_printf("stack b\n");
    display_stack(*b);
}
