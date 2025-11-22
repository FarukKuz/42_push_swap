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
