/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:09:30 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/27 17:09:39 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*end_of_stack(t_list *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_list	*bef_end_of_stack(t_list *stack)
{
	while (stack->next->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int	stack_len(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
