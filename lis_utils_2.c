/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:29:16 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 19:28:33 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_list	*push_out_lis(int *lis, t_list **stack_a, int argc, int lis_len)
{
	t_list	*stack_b;
	int		size;
	int		i;

	stack_b = NULL;
	size = argc - 1;
	i = 0;
	if (lis_len < 3)
		lis_len = 3;
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

t_list	*prepare_stack_b(t_list **stack_a, int argc)
{
	int		*lis;
	t_list	*stack_b;
	int		lis_len;

	lis_len = 0;
	lis = find_lis(*stack_a, argc, &lis_len);
	if (!lis)
		return (NULL);
	stack_b = push_out_lis(lis, stack_a, argc, lis_len);
	free(lis);
	return (stack_b);
}
