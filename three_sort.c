/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:23:52 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/04 12:07:03 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_list *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

void	three_sort(t_list **stack, int stack_size)
{
	int	first;
	int	second;
	int	third;
	int	max;

	if (stack_size == 3)
	{
		first = (*stack)->data;
		second = (*stack)->next->data;
		third = (*stack)->next->next->data;
		max = get_max(*stack);
		if (first == max)
			*stack = ra(*stack, 0);
		else if (second == max)
			rra(stack, 0);
	}
	if ((*stack)->data > (*stack)->next->data)
		*stack = sa(*stack, (*stack)->next, 0);
}
