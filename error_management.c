/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:58:34 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/01 10:57:22 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int	*unique_nbrs;
	int	i;
	int	current_nbr;

	unique_nbrs = malloc(sizeof(int) * (argc - 1));
	if (!unique_nbrs)
		error_exit();
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		if (!is_int_range(ft_atol(argv[i])))
			error_exit();
		current_nbr = (int)ft_atol(argv[i]);
		if (!is_duplicate(unique_nbrs, current_nbr, i - 1))
			error_exit();
		unique_nbrs[i - 1] = current_nbr;
		i++;
	}
	free(unique_nbrs);
}

int	is_duplicate(int *unique_nbrs, int num, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (unique_nbrs[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *arg)
{
	int	i;

	i = 0;
    if (arg[i] == '+' || arg[i] == '-')
        i++;
    if (! arg[i])
            return (0);
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
