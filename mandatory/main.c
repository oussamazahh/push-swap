
#include "ft_push_swap.h"
int main()
{
    t_stack *head;
    t_stack *head1;
    t_stack *tmp;
    int i;

    head = NULL;
    i = 0;
    while (i < 5)
    {
        ft_lstadd_back(&head, ft_lstnew((i * 10) + 1, i));
        i++;
    }
     i = 0;
    while (i < 5)
    {
        ft_lstadd_back(&head1, ft_lstnew((i * 3) + 6, i));
        i++;
    }
    tmp = head;
    while (tmp)
    {
        ft_printf(" nbr : %d", tmp->nbr);
        tmp = tmp->next;
    }
    tmp = head1;
    ft_printf("\nstack b \n");
    while (tmp)
    {
        ft_printf(" nbr : %d", tmp->nbr);
        tmp = tmp->next;
    }
    push_b(&head, &head1, "pa");
    ft_printf("\nafter\n");
    tmp = head;
    while (tmp)
    {
        ft_printf(" nbr : %d", tmp->nbr);
        tmp = tmp->next;
    }
    tmp = head1;
    ft_printf("\nstack b \n");
    while (tmp)
    {
        ft_printf(" nbr : %d", tmp->nbr);
        tmp = tmp->next;
    }
    system ("leaks a.out");
}