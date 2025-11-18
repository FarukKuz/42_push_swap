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

int    *len_lis_min(int *array_a, int argc)
{
    int    *len_lis;
    int    i;

    len_lis = malloc(sizeof(int) * argc);
    if (!len_lis)
    {
        free(array_a);
        return (NULL);
    }
    i = 0;
    while (i < argc)
    {
        len_lis[i] = 1;
        i++;
    }
    return (len_lis);
}

int    *calc_lis_lens(int *arr, int *len_lis, int n)
{
    int    i;
    int    j;

    i = 1;
    while (i < n)
    {
        j = 0;
        while (j < i)
        {
            if (arr[i] > arr[j] && len_lis[i] < len_lis[j] + 1)
                len_lis[i] = len_lis[j] + 1;
            j++;
        }
        i++;
    }
    return (len_lis);
}

int    find_max_len(int *len_lis, int n)
{
    int    max_len;
    int    i;

    max_len = 0;
    i = 0;
    while (i < n)
    {
        if (len_lis[i] > max_len)
            max_len = len_lis[i];
        i++;
    }
    return (max_len);
}

int    *create_lis(int *array_a, int *len_lis, int argc, int max_len)
{
    int    *lis;
    int    i;
    int    current_len;
    int    current_val;

    lis = malloc(sizeof(int) * max_len);
    if (!lis)
        return (NULL);
    i = 0;
    current_len = 1;
    current_val = INT_MIN;
    while (i <= argc - 1 && current_len <= max_len)
    {
        if (len_lis[i] == current_len && array_a[i] > current_val)
        {
            lis[current_len + 1] = array_a[i];
            current_val = array_a[i];
            current_len++;
        }
        i++;
    }
    return (lis);
}
