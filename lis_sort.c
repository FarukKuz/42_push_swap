/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:06:31 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/27 17:06:40 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*push_out_lis(int *lis, t_list **stack_a, int argc)
{
	t_list	*stack_b;
	int		size;
	int		i;

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

t_list	*lis_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int		*lis;
	int		*cost_for_b;
	int		*cost_for_a;
	t_list	*sorted_stack;
	int		i;
	int		size;

	// int     *total_costs;
	lis = find_LIS(*stack_a, argc);
	*stack_b = push_out_lis(lis, stack_a, argc);
	cost_for_a = find_cost_list_a(*stack_a, *stack_b);
	cost_for_b = find_cost_list_b(*stack_b);
	// total_costs = calculate_total_cost(cost_for_a, cost_for_b, argc - 1);
	i = 0;
	size = argc - 1;
	while (i < size)
	{
		do_op(stack_a, stack_b, cost_for_a[i], cost_for_b[i]);
		i++;
	}
	sorted_stack = *stack_a;
	return (sorted_stack);
}
