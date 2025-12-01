/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:32:38 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/01 13:11:34 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	check_args(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	lis_sort(&stack_a, &stack_b, argc);
	printf("\n\nSIRALANMIS\n");
	print_nodes(stack_a);

	return (0);
}
