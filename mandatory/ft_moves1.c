/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:14 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/02 14:43:47 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (b)
		(void)b;
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

void	rotate_b(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (a)
		(void)a;
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

void	rotate_a_b(t_stack **a, t_stack **b, char *str)
{
	rotate_a(a, b, "x");
	rotate_b(a, b, "x");
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	reverse_rotate_a(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	(void)*b;
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
}

void	reverse_rotate_b(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	(void)*a;
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
}
