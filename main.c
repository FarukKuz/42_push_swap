/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:32:38 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/06 19:34:57 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	printf("Count nodes: %d\n\n", argc);
	printf("A------------\n");
	stack_a = create_new_node(ft_atoi(argv[1]), NULL);
	stack_a = create_new_node(ft_atoi(argv[2]), stack_a);
	stack_a = create_new_node(ft_atoi(argv[3]), stack_a);
	stack_a = create_new_node(ft_atoi(argv[4]), stack_a);
	stack_a = sa(stack_a, stack_a->next);
	print_nodes(stack_a);

	printf("\nB------------\n");
	stack_b = create_new_node(ft_atoi(argv[5]), NULL);
	stack_b = create_new_node(ft_atoi(argv[6]), stack_b);
	stack_b = create_new_node(ft_atoi(argv[7]), stack_b);
	stack_b = create_new_node(ft_atoi(argv[8]), stack_b);
	stack_b = sb(stack_b, stack_b->next);
	print_nodes(stack_b);

	printf("\nPush B*********\n");
	stack_b = pb(&stack_a, stack_b);
	printf("+++ stack a\n");
	print_nodes(stack_a);
	printf("+++ stack b\n");
	print_nodes(stack_b);

	printf("\nPush A*********\n");
	stack_a = pb(&stack_b, stack_a);
	printf("+++ stack a\n");
	print_nodes(stack_a);
	printf("+++ stack b\n");
	print_nodes(stack_b);

	return (0);
}
