/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:53:57 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/24 15:41:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int   is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int check_correct_nbr(char **av)
{
    int j;
    int i;
    int h;

    j = 1;
    h = 0;
    while (av[j])
    {
        i = 0;
        while (av[j][i])
        {
            if (av[j][i] != '-' && av[j][i] != '+' && is_space(av[j][i]) == 0 && ft_isdigit(av[j][i]) == 0)
            {
                return (1);
            }
            if (ft_isdigit(av[j][i]) == 1)
            {
                h++;
            }
            if ((av[j][i] == '-' || av[j][i] == '+') && ft_isdigit(av[j][i + 1]) == 0)
                return (1);
            i++;
        }
        j++;
    }
    if (h == 0)
        return (1);
    return (0);
}
void    ft_free(char **all)
{
    int i;

    i = 0;
    while (all[i])
    {
        free(all[i]);
        i++;
    }
    free(all);
}

void    _fill_all(char ***all,char **split)
{
    int lenght_split;
    int lenght_all;
    char **new;
    int i;
    int j;

    lenght_all = 0;
    lenght_split = 0;
     while ((*all) && (*all)[lenght_all])
        lenght_all++;
    while ((split) && split[lenght_split])
        lenght_split++;
    new = malloc(sizeof(char *) * (lenght_all + lenght_split) + 1);
    if (!new)
        return ;
    new[(lenght_all + lenght_split)] = NULL;
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
    if (*all)
        ft_free(*all);
    (*all) = new;
}

int     check_numbers(int *tab, int a)
{
    int i = 1;
    int j;
    int tab1[a];

    tab1[0] = tab[0];
    while (i < a)
    {
        j = 0;
        while (j < i)
        {
            if (tab1[j] == tab[i])
                return (1);
            j++;
        }
        tab1[i] = tab[i];
        i++;
    }
    return (0);
}

int order_stack(t_stack *a)
{
    int nb;

    nb = -2147483648;
    while (a)
    {
        if (nb > a->nbr)
            return (1);
        nb = a->nbr;
        a = a->next;
    }
    return (0);
}
int index_of_big(t_stack *a)
{
    t_stack *tmp;
    int     big;
    int     index;

    tmp = a;
    big = a->nbr;
    index = 0;
    while (tmp)
    {
        if (big < tmp->nbr)
            big =  tmp->nbr;
        tmp = tmp->next;
    }
    tmp = a;
    while (tmp)
    {
        if (big == tmp->nbr)
            index = tmp->index;
        tmp = tmp->next;
    }
    return (index);
}

void order_in3(t_stack **a, t_stack **b)
{
    int     index;
    (void )b;
    index = index_of_big(*a);
    printf("index %d\n", index);
    if (index == 0)
    {
        rotate_a (a, b, "ra");
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
    if (index == 1)
    {
        reverse_rotate_a(a, b, "rra");
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
    if (index == 2)
    {
        if ((*a)->nbr > (*a)->next->nbr)
            swap_a(a, b, "sa");
    }
}

void    _create_stack(t_stack **a, t_stack **b, int  *tab, int   i)
{
    int j;

    j = 0;
    while (j < i)
    {
        ft_lstadd_back(a, ft_lstnew(tab[j], j));
        j++;
    }
    printf("stack a \n");
    display_stack(*a);
    if (order_stack(*a) == 1)
    {
        if (lst_size(*a) == 1)
            printf("OK\n");
        if (lst_size(*a) == 2)
        {
            rotate_a(a, NULL, "ra");
            printf("OK\n");
        }
        if (lst_size(*a) == 3)
        {
            order_in3(a, b);
            printf("after \n");
            display_stack(*a);
        }
        if (lst_size(*a) > 3)
        {
            push_swap(a, b);
        }
    }
    else
        ft_printf("OK\n");
}
void    ft_free_stack(t_stack **a, t_stack **b)
{
    while (*a)
    {
        free(*a);
        *a = NULL;
        *a = (*a)->next;
    }
    free(*a);
    while (*b)
    {
        free(*b);
        *b = (*b)->next;
    }   
    free(*b); 
}
int main(int ac, char **av)
{
    char **all = NULL;
    t_stack *a;
    t_stack *b;
    int  i;

    if (ac > 1 && check_correct_nbr(av) == 0)
    {
        i = 1;
        a = NULL;
        b = NULL;
        while (av[i])
            _fill_all(&all, ft_split(av[i++]));
        int tab[i];
        i = 0;
        while (all[i])
        {
            tab[i] = ft_atoi(all[i]);
            i++;
        }
        if (check_numbers(tab ,i) == 0)
            _create_stack(&a, &b, tab, i);
        else
            ft_printf("Error\n");
        
    }
    else
        ft_printf("Error\n");
    // while (1);
    
}
