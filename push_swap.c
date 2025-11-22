/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:53:10 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/22 18:54:16 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int data)
{
	
	return (head);
}

t_list	*create_stack(int argc, char **argv)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	i = 1;
	head->data = ft_atol(argv[i]);
	head->next = NULL;
	if (argc == 2)
		return (head);
	tmp = head;
	while (i <= argc)
	{
		tmp->next = create_new_node(ft_atol(argv[i]));
		i++;
		tmp = tmp->next;
	}
	return (head);
}

void	print_nodes(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}
