/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:38:32 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/06 20:53:33 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ra(t_list *stack_a, int flag)
{
    t_list    *tmp;
    t_list    *tmp2;

    tmp = stack_a;
    stack_a = stack_a->next;
    tmp2 = stack_a;
    while (tmp2->next)
    {
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp;
    tmp->next = NULL;
    if (!flag)
        write(1, "ra\n", 3);
    return (stack_a);
}

t_list  *rb(t_list *stack_b, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp2 = stack_b;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
    tmp2->next = tmp;
    tmp->next = NULL;
    if (!flag)
        write(1, "rb\n", 3);
	return (stack_b);
}

void  rr(t_list **stack_a, t_list **stack_b)
{
    *stack_a = ra(*stack_a, 1);
    *stack_b = rb(*stack_b, 1);
    write(1, "rr\n", 3);
}
