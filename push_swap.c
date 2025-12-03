/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:53:10 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/27 17:09:11 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*create_stack(int argc, char **args)
{
	t_list	*head;
	t_list	*end;
	t_list	*current_node;
	int		i;

	head = NULL;
	end = NULL;
	i = 1;
	while (i < argc)
	{
		current_node = create_new_node((int)ft_atol(args[i]));
		if (!current_node)
			return (NULL);
		if (head == NULL)
			head = current_node;
		else
			end->next = current_node;
		end = current_node;
		i++;
	}
	return (head);
}

t_list  *return_stack(int argc, char **argv)
{
    t_list  *stack;

    check_args(argc, argv);
    stack = create_stack(argc, argv);
    return (stack);
}

t_list    *create_stack_from_split(char **args, int size)
{
    t_list    *head;
    t_list    *end;
    t_list    *current_node;
    int        i;

    head = NULL;
    end = NULL;
    i = 0;
    while (i < size)
    {
        current_node = create_new_node((int)ft_atol(args[i]));
        if (!current_node)
            return (NULL);
        if (head == NULL)
            head = current_node;
        else
            end->next = current_node;
        end = current_node;
        i++;
    }
    return (head);
}
