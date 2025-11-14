//
//  stack_utils.h
//  
//
//  Created by Faruk Kuz on 13.11.2025.
//

#include "push_swap.h"

t_list  *end_of_stack(t_list *stack)
{
    while(stack->next)
    {
        stack = stack->next;
    }
    return (stack);
}

t_list  *bef_end_of_stack(t_list *stack)
{
    while(stack->next->next)
    {
        stack = stack->next;
    }
    return (stack);
}
