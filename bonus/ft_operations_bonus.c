/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:11:31 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 12:25:49 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, b);
	reverse_rotate_b(a, b);
}
