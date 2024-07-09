/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:12 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 17:33:03 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(t_stack **a, t_stack **b, char *str)
{
	int	tmp;

	if (lst_size(*a) == 1)
		return ;
	(void)*b;
	tmp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = tmp;
	write(1, str, ft_strlen(str));
	if (*str != '\0')
		write(1, "\n", 1);
}

void	swap_b(t_stack **a, t_stack **b, char *str)
{
	int	tmp;

	if (lst_size(*b) == 1)
		return ;
	(void)*a;
	tmp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = tmp;
	write(1, str, ft_strlen(str));
	if (*str != '\0')
		write(1, "\n", 1);
}

void	swap_a_b(t_stack **a, t_stack **b, char *str)
{
	swap_a(a, b, "");
	swap_b(a, b, "");
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	push_a(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	push_b(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
