/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:05:21 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 12:14:57 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	_check_over_under_flow(int n, int tmp, int sign)
{
	if (sign == 1)
	{
		if (tmp > n)
		{
			ft_printf("Error\n");
			exit (1);
		}
	}
	if (sign == -1)
	{
		if (tmp < n)
		{
			ft_printf("Error\n");
			exit (1);
		}
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;
	int	tmp;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = n;
		n = (n * 10) + (str[i] - 48) * sign;
		_check_over_under_flow(n, tmp, sign);
		i++;
	}
	return (n);
}
