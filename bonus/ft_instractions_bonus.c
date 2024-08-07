/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instractions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:20:43 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 23:22:25 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_exit(t_stack **a, t_stack **b, char *tmp)
{
	write(1, "Error\n", 6);
	ft_free_stack(a, b);
	free(tmp);
	exit(2);
}

static void	help(t_stack **a, t_stack **b, char *tmp)
{
	if (ft_strncmp(tmp, "pa\n", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(tmp, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(tmp, "rra\n", 4) == 0)
		reverse_rotate_a(a, b);
	else if (ft_strncmp(tmp, "rrb\n", 4) == 0)
		reverse_rotate_b(a, b);
	else if (ft_strncmp(tmp, "rrr\n", 4) == 0)
		reverse_rotate_a_b(a, b);
	else if (ft_strncmp(tmp, "ra\n", 3) == 0)
		rotate_a(a, b);
	else if (ft_strncmp(tmp, "rb\n", 3) == 0)
		rotate_b(a, b);
	else if (ft_strncmp(tmp, "rr\n", 3) == 0)
		rotate_a_b(a, b);
	else if (ft_strncmp(tmp, "sa\n", 3) == 0)
		swap_a(a, b);
	else if (ft_strncmp(tmp, "sb\n", 3) == 0)
		swap_b(a, b);
	else if (ft_strncmp(tmp, "ss\n", 3) == 0)
		swap_a_b(a, b);
	else
		ft_exit(a, b, tmp);
}

void	_instractions(t_stack **a, t_stack **b)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (tmp == NULL)
			break ;
		help(a, b, tmp);
		free(tmp);
	}
}
