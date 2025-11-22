/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:32:31 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/22 17:01:22 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sa(t_list *first_node, t_list *second_node, int flag)
{
	int	tmp;

	tmp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = tmp;
	if (!flag)
		write(1, "sa\n", 3);
	return (first_node);
}

t_list	*sb(t_list *first_node, t_list *second_node, int flag)
{
	int	tmp;

	tmp = first_node->data;
	first_node->data = second_node->data;
	second_node->data = tmp;
	if (!flag)
		write(1, "sb\n", 3);
	return (first_node);
}

void	ss(t_list *a_1, t_list *a_2, t_list *b_1, t_list *b_2)
{
	write(1, "deneme ", 7);
	a_1 = sa(a_1, a_2, 1);
	b_1 = sb(b_1, b_2, 1);
	write(1, "ss\n", 3);
}
