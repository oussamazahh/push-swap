/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:06:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 21:50:15 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

/* void   display_stack(t_stack *stack)
{
    t_stack *tmp;
    int     i;

    tmp = stack;
    i = 0;
    while (tmp != NULL)
    {
        ft_printf("[nbr %d[index %d](top
		%d)] target (%d) bestmove(%d)=> \n",tmp->nbr, tmp->index, tmp->top,
		tmp->best_match, tmp->best_move);
        tmp = tmp->next;
        i++;
    }
	printf("[NULL]\n");
}
void	display_stack2(t_stack *stack)
{
    t_stack *tmp;
    int     i;
	int	size;
	int	size;

    tmp = stack;
    i = 0;
    while (tmp != NULL)
    {
        ft_printf("[nbr %d \n",tmp->nbr);
        tmp = tmp->next;
        i++;
    }
	printf("[NULL]\n");
} */
int	lst_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	ft_exiit(void)
{
	ft_printf("Error\n");
	exit (2);
}
