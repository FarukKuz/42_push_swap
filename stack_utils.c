//
//  stack_utils.h
//
//
//  Created by Faruk Kuz on 13.11.2025.
//

#include "push_swap.h"

t_list	*end_of_stack(t_list *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_list	*bef_end_of_stack(t_list *stack)
{
	while (stack->next->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int stack_len(t_list *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}
