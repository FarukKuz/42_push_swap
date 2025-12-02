/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:06:31 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/01 18:37:06 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *find_lis(t_list *stack_a, int argc, int *lis_len)
{
	int	    *array_a;
	int	    *len_lis_list;
    int     *lis;
	int	    max_len;

	array_a = convert_array(stack_a, argc);
	if (!array_a)
		return (NULL);
	len_lis_list = len_lis_min(array_a, argc - 1);
	if (!len_lis_list)
    {
        free(array_a);
        return (NULL);
    }
	len_lis_list = calc_lis_lens(array_a, len_lis_list, argc - 1);
	max_len = find_max_len(len_lis_list, argc - 1);
	lis = create_lis(array_a, len_lis_list, argc - 1, max_len);
    *lis_len = max_len;
	free(array_a);
	free(len_lis_list);
	return (lis);
}

static int	is_in_lis(int val, int *lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lis[i] == val)
			return (1);
		i++;
	}
	return (0);
}

t_list    *push_out_lis(int *lis, t_list **stack_a, int argc, int lis_len)
{
    t_list    *stack_b;
    int        size;
    int        i;

    stack_b = NULL;
    size = argc - 1;
    i = 0;
    while (i < size - lis_len)
    {
        if (is_in_lis((*stack_a)->data, lis, lis_len))
            *stack_a = ra(*stack_a, 0);
        else
        {
            stack_b = pb(stack_a, stack_b);
            i++;
        }
    }
    return (stack_b);
}

void	do_op(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		*stack_a = ra(*stack_a, 0);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a, 0);
		cost_a++;
	}
	while (cost_b > 0)
	{
		*stack_b = rb(*stack_b, 0);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b, 0);
		cost_b++;
	}
	*stack_a = pa(*stack_a, stack_b);
}

void	edit_sorted_stack(t_list **stack_a)
{
	int	min_nbr_index;
	int	len;

	len = stack_len(*stack_a);
    min_nbr_index = find_min_index(*stack_a);
	if (min_nbr_index > len / 2)
	{
		while (min_nbr_index < len)
		{
			rra(stack_a, 0);
			min_nbr_index++;
		}
	}
	else
	{
		while (min_nbr_index > 0)
		{
			*stack_a = ra(*stack_a, 0);
			min_nbr_index--;
		}
	}
}

t_list	*prepare_stack_b(t_list *stack_a, int argc)
{
	int		*lis;
	t_list	*stack_b;
    int     lis_len;

    lis_len = 0;
	lis = find_lis(stack_a, argc, &lis_len);
	if (!lis)
		return (NULL);
	stack_b = push_out_lis(lis, &stack_a, argc, lis_len);
	free(lis);
	return (stack_b);
}

void	lis_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int		*cost_for_b;
	int		*cost_for_a;
	int		*total_cost;
	int		best_index;
	int		size_b;

	*stack_b = prepare_stack_b(*stack_a, argc);
	while (*stack_b)
	{
		size_b = stack_len(*stack_b);
		cost_for_a = find_cost_list_a(*stack_a, *stack_b);
		cost_for_b = find_cost_list_b(*stack_b);
		total_cost = calculate_total_cost(cost_for_a, cost_for_b, size_b);
		best_index = find_best_index(total_cost, size_b);
		do_op(stack_a, stack_b, cost_for_a[best_index], cost_for_b[best_index]);
		free(cost_for_a);
		free(cost_for_b);
		free(total_cost);
	}
	printf("before edit\n");
	edit_sorted_stack(stack_a);
}
