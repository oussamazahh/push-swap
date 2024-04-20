/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:53:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/18 15:21:59 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int check_correct_nbr(char **av)
{
    int j;
    int i;

    j = 1;
    while (av[j])
    {
        i = 0;
        while (av[j][i])
        {
            if (av[j][i] != '-' && av[j][i] != '+' && is_space(av[j][i]) == 0 && ft_isdigit(av[j][i]) == 0)
            {
                return (1);
            }
            i++;
        }
        j++;
    }
    return (0);
}
int   add_to(char ***all, char **split)
{
    int i = 0;
    int j = 0;
    int all_length = 0;
    int split_length = 0;
    char **new_all;

    while ((*all) && (*all)[all_length])
        all_length++;
    while (split[split_length])
        split_length++;

    new_all = (char**)malloc((all_length + split_length + 1) * sizeof(char*)); // allocate memory for 'new_all'
    if (new_all == NULL) {
        // handle error
    }

    while ((*all) && (*all)[i])
    {
        new_all[i] = (*all)[i];
        i++;
    }
    while (split[j])
    {
        new_all[i] = ft_strdup(split[j]);
        i++;
        j++;
    }
    new_all[i] = NULL; // null terminate the array

    free(*all); // free the old 'all'
    *all = new_all; // update the 'all' pointer
    return (all_length + split_length );
}

int _checknumbers(int *tab, int numbers)
{
    int i;
    int j;
    int tab1[numbers];

    i = 1;
    tab1[0] = tab[0];
    while (i < numbers)
    {
        j = 0;
        while (j < i)
        {
            if (tab1[j] == tab[i])
            {
                return (1);
            }
            j++;
        }
        tab1[i] = tab[i];
        i++;
    }
    return (0);
}
int main(int ac, char **av)
{
    char    **all;
    t_stack *head;
    int     i;
    int numbers= 0 ;
    if (ac > 1 && check_correct_nbr(av) == 0)
    {
        i = 1;
        while(i < ac)
        {
            numbers = add_to(&all, ft_split(av[i]));
            i++;
        }
        i = 0;
        head = NULL;
        int tab[numbers];
        while (all[i])
        {
            tab[i] = ft_atoi(all[i]);
            ft_lstadd_back(&head, ft_lstnew(tab[i], i));
            ft_printf("%d \n", tab[i]);
            i++;
        }
        if (_checknumbers(tab, numbers) == 0)
        {
            printf("stack a \n");
            display_stack(head);
        }
        else
        {
            ft_printf("sidna rak kt dhak elina f numbers\n");
            exit(1);
        }
    }
    else
        write(1, "sidna rak kt dhak elina\n", 24);
}