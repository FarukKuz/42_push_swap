/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:58:34 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 16:16:30 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int	*unique_nbrs;
	int	i;
	int	current_nbr;

	unique_nbrs = malloc(sizeof(int) * argc);
	if (!unique_nbrs)
		error_exit(unique_nbrs);
	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit(unique_nbrs);
		if (!is_int_range(ft_atol(argv[i])))
			error_exit(unique_nbrs);
		current_nbr = (int)ft_atol(argv[i]);
		if (!is_duplicate(unique_nbrs, current_nbr, i))
			error_exit(unique_nbrs);
		unique_nbrs[i] = current_nbr;
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
	if (!arg[i])
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

void	error_exit(int *unique_nbrs)
{
	if (unique_nbrs)
		free(unique_nbrs);
	write(2, "Error\n", 6);
	exit(1);
}
