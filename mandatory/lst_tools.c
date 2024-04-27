/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:50:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/26 15:24:23 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void    del_first(t_stack **stack)
{
    t_stack *tmp;

	if (!stack || !(*stack))
		return ;
    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
}

void    del_last(t_stack **stack)
{
    t_stack *tmp;

	if (!stack || !(*stack))
		return ;
    tmp = *stack;
	if (tmp->next == NULL)
	{
		free(tmp);
		tmp = NULL;
		return ;
	}
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

t_stack	*ft_lstlast(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
