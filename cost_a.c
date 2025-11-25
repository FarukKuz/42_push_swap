//
//  cost_a.c
//  push_swap
//
//  Created by Faruk Kuz on 24.11.2025.
//

#include "push_swap.h"

int    *find_cost_list(t_list *stack_b)
{
    int        *cost_list;
    int        size;
    int        i;
    t_list    *tmp;

    size = stack_len(stack_b);
    cost_list = (int *)malloc(sizeof(int) * size);
    if (!cost_list)
        return (NULL);
    i = 0;
    tmp = stack_b;
    while (tmp)
    {
        if (i <= size / 2)
            cost_list[i] = i;
        else
            cost_list[i] = (size - i) * -1;
        i++;
        tmp = tmp->next;
    }
    return (cost_list);
}
