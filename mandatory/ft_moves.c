/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:12 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 16:47:57 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    swap_a(t_stack **a, t_stack **b, char *str)
{
    int     tmp;
    (void )*b;

    tmp = (*a)->nbr;
    (*a)->nbr = (*a)->next->nbr;
    (*a)->next->nbr = tmp;
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
    // reset_index(a, b);
}

void    swap_b(t_stack **a, t_stack **b, char *str)
{
    int     tmp;
    (void )*a;

    tmp = (*b)->nbr; 
    (*b)->nbr = (*b)->next->nbr;
    (*b)->next->nbr = tmp;
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
    // reset_index(a, b);
}

void    swap_a_b(t_stack **a, t_stack **b, char *str)
{
    swap_a(a, b, "");
    swap_b(a, b, "");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    // reset_index(a, b);
}

void    push_a(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    // reset_index(a, b);
}

void    push_b(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;

    if (!*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    // reset_index(a, b);
}

void    rotate_a(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;
    t_stack *tmp1;
    if (b)
        (void )b;
    
    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    tmp1 = *a;
    while ((*a)->next)
        *a = (*a)->next;
    (*a)->next = tmp;
    *a = tmp1;
    if (*str != 'x')
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
    }
}
void    rotate_b(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;
    t_stack *tmp1;
    if (a)
        (void )a;
    
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    tmp1 = *b;
    while ((*b)->next)
        *b = (*b)->next;
    (*b)->next = tmp;
    *b = tmp1;
    if (*str != 'x')
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
    }
}

void    rotate_a_b(t_stack **a, t_stack **b, char *str)
{
    rotate_a(a, b, "x");
    rotate_b(a, b, "x");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    // reset_index(a, b);
}

void    reverse_rotate_a(t_stack **a, t_stack **b, char *str)
{
    t_stack     *tmp;
    t_stack     *tmp1;
    (void )*b;

    tmp1 = *a;
    while (tmp1->next->next)
        tmp1 = tmp1->next;
    tmp = tmp1->next;
    tmp1->next = NULL;
    tmp->next = *a;
    *a = tmp;
    if (*str != 'x')
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
    }
    // reset_index(a, b);
}

void    reverse_rotate_b(t_stack **a, t_stack **b, char *str)
{
    t_stack     *tmp;
    t_stack     *tmp1;
    (void )*a;

    tmp1 = *b;
    while (tmp1->next->next)
        tmp1 = tmp1->next;
    tmp = tmp1->next;
    tmp1->next = NULL;
    tmp->next = *b;
    *b = tmp;
    if (*str != 'x')
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
    }
    // reset_index(a, b);
}

void    reverse_rotate_a_b(t_stack **a, t_stack **b, char *str)
{
    reverse_rotate_a(a, b, "x");
    reverse_rotate_b(a, b, "x");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    // reset_index(a, b);
}
