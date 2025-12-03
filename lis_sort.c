/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:06:31 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 19:20:02 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	edit_sorted_stack(t_list **stack_a)
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

static void	do_op_2(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a < 0)
	{
		rra(stack_a, 0);
		cost_a++;
	}
	while (cost_b < 0)
	{
		rrb(stack_b, 0);
		cost_b++;
	}
}

static void	do_op_1(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		*stack_a = ra(*stack_a, 0);
		cost_a--;
	}
	while (cost_b > 0)
	{
		*stack_b = rb(*stack_b, 0);
		cost_b--;
	}
	do_op_2(stack_a, stack_b, cost_a, cost_b);
	*stack_a = pa(*stack_a, stack_b);
}

void	lis_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*cost_for_b;
	int	*cost_for_a;
	int	*total_cost;
	int	best_index;
	int	size_b;

	*stack_b = prepare_stack_b(stack_a, argc);
	if (stack_len(*stack_a) <= 3)
		three_sort(stack_a);
	while (*stack_b)
	{
		size_b = stack_len(*stack_b);
		cost_for_a = find_cost_list_a(*stack_a, *stack_b);
		cost_for_b = find_cost_list_b(*stack_b);
		total_cost = calculate_total_cost(cost_for_a, cost_for_b, size_b);
		best_index = find_best_index(total_cost, size_b);
		do_op_1(stack_a, stack_b, cost_for_a[best_index],
			cost_for_b[best_index]);
		free(cost_for_a);
		free(cost_for_b);
		free(total_cost);
	}
	edit_sorted_stack(stack_a);
}
