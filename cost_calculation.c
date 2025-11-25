//
//  cost.c
//  push_swap
//
//  Created by Faruk Kuz on 25.11.2025.
//

#include "push_swap.h"

static int calc_abs(int nbr)
{
    if (nbr < 0)
        nbr *= -1;
    return (nbr);
}

int *calculate_total_cost(int *cost_to_a, int *cost_to_b, int size)
{
    int *total_cost;
    int i;

    total_cost = malloc(sizeof(int) * size);
    if (!total_cost)
        return (NULL);
    i = 0;
    while (i < size)
    {
        if (cost_to_a[i] < 0 && cost_to_b[i] < 0)
        {
            if (cost_to_a[i] > cost_to_b[i])
                total_cost[i] = cost_to_b[i] * -1;
            else
                total_cost[i] = cost_to_a[i] * -1;
        }
        else if (cost_to_a[i] > 0 && cost_to_b[i] > 0)
        {
            if (cost_to_a[i] < cost_to_b[i])
                total_cost[i] = cost_to_b[i];
            else
                total_cost[i] = cost_to_a[i];
        }
        else
            total_cost[i] = calc_abs(cost_to_a[i]) + calc_abs(cost_to_b[i]);
        i++;
    }
    return (total_cost);
}
