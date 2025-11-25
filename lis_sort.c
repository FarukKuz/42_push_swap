//
//  lis_sort.c
//  push_swap
//
//  Created by Faruk Kuz on 18.11.2025.
//

#include "push_swap.h"

int	*find_LIS(t_list *stack_a, int argc)
{
	int	*array_a;
	int	*len_lis;
	int	*lis;
	int	max_len;

	array_a = convert_array(stack_a, argc);
	if (!array_a)
		return (NULL);
	len_lis = len_lis_min(array_a, argc - 1);
	if (!len_lis)
		return (NULL);
	len_lis = calc_lis_lens(array_a, len_lis, argc - 1);
	max_len = find_max_len(len_lis, argc - 1);
	lis = create_lis(array_a, len_lis, argc - 1, max_len);
	free(array_a);
	free(len_lis);
	return (lis);
}

static int    is_in_lis(int val, int *lis, int size)
{
    int    i;

    i = 0;
    while (i < size)
    {
        if (lis[i] == val)
            return (1);
        i++;
    }
    return (0);
}

t_list    *push_out_lis(int *lis, t_list **stack_a, int argc)
{
    t_list    *stack_b;
    int        size;
    int        i;

    stack_b = NULL;
    size = argc - 1;
    i = 0;
    while (i < size)
    {
        if (is_in_lis((*stack_a)->data, lis, size))
            *stack_a = ra(*stack_a, 1);
        else
            stack_b = pb(stack_a, stack_b);
        i++;
    }
    return (stack_b);
}
