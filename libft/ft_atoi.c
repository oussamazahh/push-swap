/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:05:21 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/26 17:56:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			n;

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
		n = (n * 10) + (str[i] - 48);
		if (n > INT_MAX || n < INT_MIN)
		{
			write(1, "ERROR", 5);
			exit (0);
		}	
			
			
		// if (n > 9223372036854775807 && sign == -1)
		// 	return (0);
		// if (n > 9223372036854775807 && sign == 1)
		// 	return (-1);
		i++;
	}
	return ((int)n * sign);
}
