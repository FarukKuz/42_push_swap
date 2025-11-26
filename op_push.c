/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:37:45 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/22 17:00:29 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pb(t_list **stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = stack_b;
	write(1, "pb\n", 3);
	return (tmp);
}

t_list	*pa(t_list *stack_a, t_list **stack_b)
{
	t_list	*tmp;

    if (!stack_b || !*stack_b)
            return (stack_a);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = stack_a;
	write(1, "pa\n", 3);
	return (tmp);
}
