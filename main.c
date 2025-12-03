/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:32:38 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/01 18:25:40 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
    char    **args;
    int     x = 0;

    args = NULL;
    printf("split oncesi\n");
    args = split_args(argc, argv);
    printf("split sonrasi\n");
    x = count_args(args);
    printf("%d - ", x);
	check_args(argc, args);
    printf("check error oncesi\n");
	stack_a = create_stack(argc, args);
	stack_b = NULL;
	lis_sort(&stack_a, &stack_b, argc);
    free_stack(stack_a);
    free_stack(stack_b);
    free_args(args);
	return (0);
}
