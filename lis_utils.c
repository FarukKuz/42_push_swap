//
//  lis_utils.c
//  push_swap
//
//  Created by Faruk Kuz on 15.11.2025.
//

#include "push_swap.h"

int *convert_array(t_list *stack, int argc)
{
    int *array;
    int i;

    array = malloc(sizeof(int) * (argc - 1));
    if (!array)
        return (NULL);
    i = 0;
    while(stack)
    {
        array[i] = stack->data;
        stack = stack->next;
        i++;
    }
    return (array);
}

int find_lis_len(t_list *current_node)
{
    int     len;
    t_list  *i;

    len = 0;
    i = current_node;
    while (current_node->data < i->data)
    {
        i = i->next;
        len++;
    }
    return (len);
}

int find_max_len(int *array_a)
{
    int max_len;
    int i;
    int j;

    i = 0;
    j = 1;
    max_len = array_a[i];
    while (array_a[i])
    {
        while (array_a[j])
        {
            if (array_a[j] > array_a[i])
            {
                max_len = array_a[j];
                break;
            }
            j++;
        }
        i = j;
    }
    return (max_len);
}

int *find_LIS(t_list *stack_a, int argc)
{
    int     *LIS;
    int     *array_a;
    int     *len_lis;
    int     max_len;
    int     i;

    array_a = convert_array(stack_a, argc);
    if (!array_a)
        return (NULL);
    max_len = 0;
    i = 0;
    while (array_a[i])
    {
        len_lis[i] = find_lis_len(stack_a);
        
    }
    free (array_a);
    return (LIS);
}
