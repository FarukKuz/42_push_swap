/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:32:38 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 18:39:46 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		args_count;

	if (argc < 2)
		return (0);
	args = split_args(argc, argv);
	if (!args)
		return (1);
	args_count = count_args(args);
	if (args_count == 0)
	{
		free_args(args);
		return (0);
	}
	stack_a = return_stack(args_count, args);
	stack_b = NULL;
	lis_sort(&stack_a, &stack_b, args_count + 1);
	free_stack(stack_a);
	free_stack(stack_b);
	free_args(args);
	return (0);
}
