/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:07:53 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/27 17:08:02 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static void    get_calc_cost(int **total_cost, int *cost_to_a, int *cost_to_b, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (cost_to_a[i] < 0 && cost_to_b[i] < 0)
        {
            if (cost_to_a[i] > cost_to_b[i])
                *total_cost[i] = cost_to_b[i] * -1;
            else
                *total_cost[i] = cost_to_a[i] * -1;
        }
        else if (cost_to_a[i] > 0 && cost_to_b[i] > 0)
        {
            if (cost_to_a[i] < cost_to_b[i])
                *total_cost[i] = cost_to_b[i];
            else
                *total_cost[i] = cost_to_a[i];
        }
        else
            *total_cost[i] = calc_abs(cost_to_a[i]) + calc_abs(cost_to_b[i]);
        i++;
    }
}

int	*calculate_total_cost(int *cost_to_a, int *cost_to_b, int size)
{
	int	*total_cost;
	int	i;

	total_cost = malloc(sizeof(int) * size);
	if (!total_cost)
		return (NULL);
    get_calc_cost(&total_cost, cost_to_a, cost_to_b, size);
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
