/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:07:53 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 16:28:09 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static void	get_calc_cost(int *t_cost, int *cost_a, int *cost_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (cost_a[i] < 0 && cost_b[i] < 0)
		{
			if (cost_a[i] > cost_b[i])
				t_cost[i] = cost_b[i] * -1;
			else
				t_cost[i] = cost_a[i] * -1;
		}
		else if (cost_a[i] > 0 && cost_b[i] > 0)
		{
			if (cost_a[i] < cost_b[i])
				t_cost[i] = cost_b[i];
			else
				t_cost[i] = cost_a[i];
		}
		else
			t_cost[i] = calc_abs(cost_a[i]) + calc_abs(cost_b[i]);
		i++;
	}
}

int	*calculate_total_cost(int *cost_a, int *cost_b, int size)
{
	int	*total_cost;

	total_cost = malloc(sizeof(int) * size);
	if (!total_cost)
		return (NULL);
	get_calc_cost(total_cost, cost_a, cost_b, size);
	return (total_cost);
}

int	find_best_index(int *total_costs, int size)
{
	int	i;
	int	min_cost;
	int	best_index;

	min_cost = 2147483647;
	best_index = -1;
	i = 0;
	while (i < size)
	{
		if (total_costs[i] < min_cost)
		{
			min_cost = total_costs[i];
			best_index = i;
		}
		i++;
	}
	return (best_index);
}
