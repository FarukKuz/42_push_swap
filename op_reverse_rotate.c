//
//  reverse_operations.c
//  
//
//  Created by Faruk Kuz on 13.11.2025.
//

#include "push_swap.h"

void    rra(t_list **stack_a, int flag)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = end_of_stack(*stack_a);
    bef_end_of_stack(*stack_a)->next = NULL;
    tmp2 = *stack_a;
    *stack_a = tmp;
    (*stack_a)->next = tmp2;
    if (!flag)
        write(1, "rra\n", 4);
}

void    rrb(t_list **stack_b, int flag)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = end_of_stack(*stack_b);
    bef_end_of_stack(*stack_b)->next = NULL;
    tmp2 = *stack_b;
    *stack_b = tmp;
    (*stack_b)->next = tmp2;
    if (!flag)
        write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a, 1);
    rrb(stack_b, 1);
    write(1, "rrr\n", 4);
}
