/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:53:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 15:55:55 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_space_sign(char c)
{
	if ((c == ' ' || c == '\t') || (c == '-' || c == '+'))
		return (1);
	return (0);
}

int	check_correct_nbr(char **av)
{
	int	j;
	int	i;
	int	h;

	j = 1;
	while (av[j])
	{
		i = 0;
		h = 0;
		while (av[j][i])
		{
			if (is_space_sign(av[j][i]) == 0 && ft_isdigit(av[j][i]) == 0)
				return (1);
			if (ft_isdigit(av[j][i]) == 1)
				h++;
			if ((av[j][i] == '-' || av[j][i] == '+') && ft_isdigit(av[j][i
					+ 1]) == 0)
				return (1);
			i++;
		}
		if (h == 0)
			return (1);
		j++;
	}
	return (0);
}

void	_fill_all(char ***all, char **split, int *len_all)
{
	int		lenght_split;
	int		lenght_all;
	char	**new;
	int		i;
	int		j;

	lenght_all = len_double_p(*all);
	lenght_split = len_double_p(split);
	new = malloc(sizeof(char *) * (lenght_all + lenght_split + 1));
	if (!new)
		return ;
	i = 0;
	while ((*all) && (*all)[i])
	{
		new[i] = ft_strdup((*all)[i]);
		i++;
	}
	j = 0;
	while ((split) && split[j])
		new[i++] = split[j++];
	free(split);
	ft_free(*all);
	new[i] = NULL;
	*len_all = i;
	(*all) = new;
}

void	_create_stack(t_stack **a, t_stack **b, int *tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		ft_lstadd_back(a, ft_lstnew(tab[j], j));
		j++;
	}
	sort_stack(a, b);
}

int	main(int ac, char **av)
{
	char	**all;
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		len_all;

	if (ac > 1)
	{
		if (check_correct_nbr(av) == 0)
		{
			i = 1;
			len_all = 0;
			a = NULL;
			b = NULL;
			all = NULL;
			while (av[i])
				_fill_all(&all, ft_split(av[i++]), &len_all);
			_create_tab(all, &a, &b, len_all);
			ft_free_stack(&a, &b);
		}
		else
			ft_exiit();
	}
}
