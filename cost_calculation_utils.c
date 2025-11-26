//
//  cost_a.c
//  push_swap
//
//  Created by Faruk Kuz on 24.11.2025.
//

#include "push_swap.h"

int    *find_cost_list_b(t_list *stack_b)
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

static int    find_min_index(t_list *stack)
{
    int        min_value;
    int        min_index;
    int        i;

    min_value = 2147483647;
    min_index = 0;
    i = 0;
    while (stack)
    {
        if (stack->data < min_value)
        {
            min_value = stack->data;
            min_index = i;
        }
        stack = stack->next;
        i++;
    }
    return (min_index);
}

static int    index_target_a(t_list *stack_a, int current_value)
{
    int        index;
    t_list    *tmp;
    long       big_value;
    int        i;

    target_index = -1;
    closest_bigger_val = 2147483648;
    tmp = stack_a;
    i = 0;
    while (tmp)
    {
        if (tmp->data > current_value && tmp->data < big_value)
        {
            big_value = tmp->data;
            index = i;
        }
        tmp = tmp->next;
        i++;
    }
    if (index == -1)
        return (find_min_index(stack_a));
    return (index);
}

int    *find_cost_list_a(t_list *stack_a, t_list *stack_b)
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
        cost_list[i] = index_target_a(stack_a, tmp->data);
        if (cost_list[i] > size / 2)
            cost_list[i] = (size - cost_list[i]) * -1;
        tmp = tmp->next;
        i++;
    }
    return (cost_list);
}
