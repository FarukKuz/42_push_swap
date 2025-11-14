/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:53:10 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/06 16:32:29 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int data, t_list *head)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL)
		return (new_node);
	new_node->next = head;
	head = new_node;
	return (new_node);
}

t_list  *create_stack(int argc, char **argv)
{
    t_list  *stack;
    int     i;

    stack = NULL;
    i = 1;
    while (i < argc)
    {
        stack = create_new_node(ft_atol(argv[i]), stack);
        i++;
    }
    return (stack);
}

t_list	*uptade_head_node(t_list *head, t_list *new_node)
{
	if (new_node == NULL)
		return (head);
	new_node->next = head;
	head = new_node;
	return (head);
}

void	print_nodes(t_list	*head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}


