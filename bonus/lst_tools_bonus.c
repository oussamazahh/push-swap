/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:50:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/04 21:14:46 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*cel;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		cel = *stack;
		while (cel->next != NULL)
			cel = cel->next;
		cel->next = new;
	}
}

t_stack	*ft_lstnew(int nb, int i)
{
	t_stack	*cel;

	cel = (t_stack *)malloc(sizeof(t_stack));
	if (!cel)
		return (NULL);
	cel->next = NULL;
	cel->nbr = nb;
	cel->index = i;
	return (cel);
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}
