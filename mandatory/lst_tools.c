/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:50:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/16 19:18:34 by ozahidi          ###   ########.fr       */
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

    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
}

void    del_last(t_stack **stack)
{
    t_stack *tmp;
    // t_stack *tmp1;

    tmp = *stack;
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			free(tmp->next);
			break ;
		}
		tmp = tmp->next;
	}
	tmp->next = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int    ft_lstsize(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}