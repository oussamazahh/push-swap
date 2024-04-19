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

int   is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

int main(int ac, char **av)
{

    if (ac > 1 && check_correct_nbr(av) == 0)
    {
        
        printf("sidna raak nadi");
    }
    else
        write(1, "sidna rak kt dhak elina\n", 24);
    // t_stack *head;
    // t_stack *head1;
    // int     i;
    
    // if (ac > 1)
    // {
    //     head = NULL;
    //     head1 = NULL;
    //     i = 1;
        
    //     while (av[i])
    //     {
    //         ft_lstadd_back(&head, ft_lstnew(ft_atoi(av[i]), i));
    //         i++;
    //     }
    //     i = 1;
    //     while (av[i])
    //     {
    //         ft_lstadd_back(&head1, ft_lstnew((ft_atoi(av[i]) + 10), i));
    //         i++;
    //     }
    //     // printf("stack a \n");/
    //     // display_stack(head);
    //     // printf("\nstack b \n");
    //     // display_stack(head1);
    //     reverse_rotate_a_b(&head, &head1, "rrr");
        // printf("\n-----------AFTER-----------\n");
        // printf("\nstack a \n");
        // display_stack(head);
        // printf("\nstack b \n");
        // display_stack(head1);
        // while (1);

    // }
}