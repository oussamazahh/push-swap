/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:20:26 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 16:05:05 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	order_stack(t_stack *a)
{
	int	nb;

	nb = a->nbr;
	while (a)
	{
		if (nb > a->nbr)
			return (1);
		nb = a->nbr;
		a = a->next;
	}
	return (0);
}

int	check_numbers(int *tab, int a)
{
	int	*tab1;
	int	i;
	int	j;

	tab1 = malloc(sizeof(int) * a);
	if (!tab1)
		return (-1);
	i = 1;
	tab1[0] = tab[0];
	while (i < a)
	{
		j = 0;
		while (j < i)
		{
			if (tab1[j] == tab[i])
				return (free(tab1), 1);
			j++;
		}
		tab1[i] = tab[i];
		i++;
	}
	free(tab1);
	return (0);
}

void	ft_exit_double(int *tab)
{
	ft_printf("Error\n");
	free(tab);
	exit (2);
}

void	_create_tab(char **all, t_stack **a, t_stack **b, int i)
{
	int	*tab;
	int	err;

	err = 0;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return ;
	i = 0;
	while (all[i])
	{
		tab[i] = ft_atoi(all[i], &err);
		if (err == 1)
		{
			free(tab);
			ft_free(all);
			exit(1);
		}
		i++;
	}
	ft_free(all);
	if (check_numbers(tab, i) == 0)
		_create_stack(a, b, tab, i);
	else
		ft_exit_double(tab);
	free(tab);
}

int	len_double_p(char **double_all)
{
	int		lenght_all;

	lenght_all = 0;
	while ((double_all) && (double_all)[lenght_all])
		lenght_all++;
	return (lenght_all);
}
