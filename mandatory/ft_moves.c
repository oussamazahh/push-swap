/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:12 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/16 19:37:20 by ozahidi          ###   ########.fr       */
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
}

void    swap_a_b(t_stack **a, t_stack **b, char *str)
{
    swap_a(a, b, "");
    swap_b(a, b, "");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

void    push_a(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;

    if (!*b)
        return ;
    tmp = ft_lstnew((*b)->nbr, 0);
    ft_lstadd_front(a, tmp);
    del_first(b);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

void    push_b(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;

    if (!*a)
        return ;
    tmp = ft_lstnew((*a)->nbr, 0);
    ft_lstadd_front(b, tmp);
    del_first(a);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

void    rotate_a(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;
    (void )*b;

    tmp = ft_lstnew((*a)->nbr, 0);
    del_first(a);
    ft_lstadd_back(a, tmp);
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
}

void    rotate_b(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;
    (void )*a;

    tmp = ft_lstnew((*b)->nbr, 0);
    del_first(b);
    ft_lstadd_back(b, tmp);
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
}

void    rotate_a_b(t_stack **a, t_stack **b, char *str)
{
    rotate_a(a, b, "");
    rotate_b(a, b, "");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

void    reverse_rotate_a(t_stack **a, t_stack **b, char *str)
{
    int     nb;
    (void )*b;

    nb = ft_lstlast(*a)->nbr;
    del_last(a);
    ft_lstadd_front(a, ft_lstnew(nb, 0));
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
}

void    reverse_rotate_b(t_stack **a, t_stack **b, char *str)
{
    int     nb;
    (void )*a;

    nb = ft_lstlast(*b)->nbr;
    del_last(b);
    ft_lstadd_front(b, ft_lstnew(nb, 0));
    write(1, str, ft_strlen(str));
    if (*str != '\0')
        write(1, "\n", 1);
}

void    reverse_rotate_a_b(t_stack **a, t_stack **b, char *str)
{
    reverse_rotate_a(a, b, "");
    reverse_rotate_b(a, b, "");
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}
