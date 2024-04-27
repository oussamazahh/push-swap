/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:11:31 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 21:15:15 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_calucule_top(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    // reset_index(a, b);
    if (a)
    {
        tmp = *a;
        while (tmp)
        {
            if (tmp->index <= (lst_size(*a)/2))
                tmp->top = 1;
            else
                tmp->top = 0;
            tmp = tmp->next;
        }
        
    }
    if (b)
    {    
        tmp = *b;
        while (tmp)
        {
            if (tmp->index <= (lst_size(*b)/2))
                tmp->top = 1;
            else
                tmp->top = 0;
            tmp = tmp->next;
        }
    }
}

char ft_smallest_larger_nbr(t_stack *stack, int nbr, int *smallest_larger)
{
    *smallest_larger = INT_MAX;

    while (stack)
    {
        if (stack->nbr > nbr && stack->nbr < *smallest_larger)
        {
            *smallest_larger = stack->nbr;
        }
        stack = stack->next;
    }
    if (*smallest_larger == INT_MAX)
        return ('x');
    else
        return ('y');
}
int ft_smallest_nbr(t_stack *stack)
{
    int smallest_larger = INT_MAX;

    while (stack)
    {
        if (stack->nbr < smallest_larger)
        {
            smallest_larger = stack->nbr;
        }
        stack = stack->next;
    }
    return (smallest_larger);
}

void ft_best_match(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *tmp1;
    int  smallest_larger;

    tmp = *a;
    tmp1 = *b;
    while (tmp1)
    {
        if (ft_smallest_larger_nbr(*a, tmp1->nbr, &smallest_larger) == 'x') // if no number in stack a is larger than tmp1->nbr
        {
            smallest_larger = ft_smallest_nbr(*a); // use the smallest number in stack a as the best match
        }
        while  (tmp)
        {
            if (tmp->nbr == smallest_larger)
            {
                tmp1->best_match = tmp->nbr; // replace the smallest larger number in stack a with the number from stack b
            }
            tmp = tmp->next;
        }
        tmp = *a; // reset tmp to the start of stack a for the next iteration of tmp1
        tmp1 = tmp1->next;
    }
}

void    ft_calcule_moves(t_stack **a, t_stack **b)
{
    (void)a;
    t_stack *tmp;

    tmp = *b;
    while (tmp)
    {
        if(tmp->top == 1)
            tmp->moves = tmp->index;
        if (tmp->top == 0)
            tmp->moves = lst_size(*b) - tmp->index;
        tmp = tmp->next;
    }
    tmp = *a;
    while (tmp)
    {
        if(tmp->top == 1)
            tmp->moves = tmp->index;
        if (tmp->top == 0)
            tmp->moves = lst_size(*a) - tmp->index;
        tmp = tmp->next;
    }
}
int ft_get_moves(t_stack *a, int best_match)
{
    while (a)
    {
        if (a->nbr == best_match)
            return (a->moves);
        a = a->next;
    }
    return (-1);
}
void    ft_calucule_all_moves(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    (void)a;

    tmp = *b;
    while (tmp)
    {
        tmp->all_moves = tmp->moves + ft_get_moves(*a, tmp->best_match);
        tmp = tmp->next;
    }
    
}
void    ft_best_move(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    (void)a;
    int min = INT_MAX;

    tmp = *b;
    while (tmp)
    {
        if (min > tmp->all_moves)
            min = tmp->all_moves;
        tmp = tmp->next;
    }
    tmp = *b;
    while (tmp)
    {
        if (min == tmp->all_moves)
            tmp->best_move = 1;
        else
            tmp->best_move = 0;
        tmp = tmp->next;
    }
}

t_stack    *serach_and_return(t_stack *a, int nbr)
{
    t_stack *tmp;

    tmp = a;
    while (tmp)
    {
        if (tmp->nbr == nbr)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
void    ft_check_a(t_stack **a, t_stack **b,t_stack *check, char c)
{
    t_stack *tmp;
    t_stack *tmp2;
    int check_nb = check->nbr;

    if (c == 'a')
    {
        tmp = *a;
        tmp2 = *a;
        
    }
    if (c == 'b')
    {
        tmp = *b;
        tmp2 = *b;
    }
    while (tmp2 && tmp2->nbr != check_nb)
    {
        reset_index(a , b);
        ft_calucule_top(a, b);
        // if (c == 'a')
        //     ft_printf("--------target in a %d from b %d-------------------", check->nbr, tmp->nbr);
        // if (c == 'b')
        //     ft_printf("--------target in b %d from a %d-------------------", check->nbr, tmp->nbr);
        if (check->top == 1)
        {
            if (c == 'a')
                rotate_a(a, b, "ra");
            if (c == 'b')
                rotate_b(a, b, "rb");
            
        }
        else if (check->top == 0)
        {
            if (c == 'a')
                reverse_rotate_a(a, b, "rra");
            if (c == 'b')
                reverse_rotate_b(a, b, "rrb");
            // exit(0);
            // ft_printf("")
            // sleep(4);
        }
        if (c == 'a')
            tmp2 = *a;
        if (c == 'b')
            tmp2 = *b;
    }
    
}

void    ft_move_to_first(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *tmp1;
    t_stack *this;
    // t_stack *new;
    int num;
    int num_b;

    tmp = *a;
    tmp1 = *b;
    while (tmp1)
    {
        if(tmp1->best_move == 1)
        {
            reset_index(a, b);
            ft_calucule_top(a, b);
            this = serach_and_return(*a, tmp1->best_match);
            num = this->nbr;
            num_b = tmp1->nbr;
            if (tmp1->top == 1 && this->top == 1)
            {
                while ((*a)->nbr != num && (*b)->nbr != num_b)
                {
                    // this = serach_and_return(*a, tmp1->best_match);
                    rotate_a_b(a, b, "rr");
                }
                
            }
            else if (tmp1->top == 0 && this->top == 0)
            {
            //    int i = 0;
                while ((*a)->nbr != num && (*b)->nbr != num_b)
                {
                    // this = serach_and_return(*a, tmp1->best_match);
                    // ft_printf("B %d : update to %d\n", (*b)->nbr , tmp1->nbr);
                    reverse_rotate_a_b(a, b, "rrr");
                //    ft_printf("A %d : update to \n", (*a)->nbr);
                    // i++;
                    // if (i == 1)
                    // {
                    //     ft_printf("stack a \n");
                    //     display_stack(*a);
                    //     ft_printf("stack b \n");
                    //     display_stack(*b);
                    //     // exit(0);
                    // }
                }
            }
            
            // ft_printf("--------target in a %d from b %d-------------------", (*a)->nbr, this->nbr);
        //     ft_printf("--------target in b %d from a %d-------------------", this->nbr, (*b)->nbr);
        // ft_printf("stack a \n");
        // display_stack(*a);
        // ft_printf("stack b \n");
        // display_stack(*b);
            // exit(0);
            // this = serach_and_return(*a, tmp1->best_match);/
            // ft_printf("this = %d\n",this->nbr);
            // exit(1);
            ft_check_a(a , b, this, 'a');
            ft_check_a(a , b, tmp1, 'b');
            
            break;
            // ft_check_b(a, b ,tmp1);
        }
        tmp1 = tmp1->next;
    }
    
}
t_stack *get_min_nbr(t_stack *a)
{
    int min = a->nbr;
    t_stack *tmp;

    tmp = a;
    while (tmp)
    {
        if (tmp->nbr < min)
            min = tmp->nbr;
        tmp = tmp->next;
    }
    tmp = a;
    while (tmp)
    {
        if (min == tmp->nbr)
            return (tmp);
        tmp = tmp->next;
    }
    return (tmp);
}
void    push_swap(t_stack **a, t_stack **b)
{
    int avg;
    t_stack *tmp;

    avg = 0;
    (void) b;
    tmp = *a;
    while (*a && lst_size(*a) > 3)
    {
        ft_calucule_top(a, b);
        if ((*a)->nbr < (int)ft_calcule_moyen(*a, lst_size(*a)))
        {
            push_b(a, b, "pb");
        }
        else
        {
            // ft_printf("%d", (int)ft_calcule_moyen(*a, lst_size(*a)));  
            rotate_a(a, b, "ra");
            
            // sleep(2);
        }
    }
    reset_index(a, b);
    order_in3(a, b);
    while (lst_size(*b))
    {
        ft_calucule_top(a, b);
        ft_best_match(a, b);
        ft_calcule_moves(a, b);
        ft_calucule_all_moves(a, b);
        ft_best_move(a, b);
        ft_move_to_first(a, b);
        push_a(a, b, "pa");
        reset_index(a, b);
    }  
//    ft_printf("9bal lowla\n");
//  ft_calucule_top(a, b);
    t_stack *min;
    int min_nbr;
    // tmp = *a;
    
    min = get_min_nbr(*a);
    min_nbr = min->nbr;
    // ft_printf("min %d\n", min_nbr);
    reset_index(a, b);
    ft_calucule_top(a, b);
    
    if (min->top)
    {
        while ((*a)->nbr != min_nbr)
        {
        
            rotate_a(a, b , "ra");
        }
        
    }else
    {
        while ((*a)->nbr != min_nbr)
        {
            reverse_rotate_a(a, b , "rra");
        }
    }
    
    // ft_printf("stack a\n");
    // if (!order_stack(*a))
        // ft_printf("nadi");
    // display_stack2(*a);
    // ft_printf("stack b\n");
    // display_stack(*b);
    // ft_printf("after\n");
    // ft_printf("after\n");
}
