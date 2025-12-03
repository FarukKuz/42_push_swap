/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:07:32 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 17:43:26 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*len_lis_min(int *array_a, int argc)
{
	int	*len_lis;
	int	i;

	len_lis = malloc(sizeof(int) * argc);
	if (!len_lis)
	{
		free(array_a);
		return (NULL);
	}
	i = 0;
	while (i < argc)
	{
		len_lis[i] = 1;
		i++;
	}
	return (len_lis);
}

static int	*calc_lis_lens(int *arr, int *len_lis, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && len_lis[i] < len_lis[j] + 1)
				len_lis[i] = len_lis[j] + 1;
			j++;
		}
		i++;
	}
	return (len_lis);
}

static int	find_max_len(int *len_lis, int n)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = 0;
	while (i < n)
	{
		if (len_lis[i] > max_len)
			max_len = len_lis[i];
		i++;
	}
	return (max_len);
}

static int	*create_lis(int *array_a, int *len_lis, int argc, int max_len)
{
	int	*lis;
	int	i;
	int	current_val;

	lis = malloc(sizeof(int) * max_len);
	if (!lis)
		return (NULL);
	i = argc - 1;
	current_val = INT_MAX;
	while (i >= 0 && max_len >= 1)
	{
		if (len_lis[i] == max_len && current_val > array_a[i])
		{
			lis[max_len - 1] = array_a[i];
			current_val = array_a[i];
			max_len--;
		}
		i--;
	}
	return (lis);
}

int	*find_lis(t_list *stack_a, int argc, int *lis_len)
{
	int	*array_a;
	int	*len_lis_list;
	int	*lis;
	int	max_len;

	array_a = convert_array(stack_a, argc);
	if (!array_a)
		return (NULL);
	len_lis_list = len_lis_min(array_a, argc - 1);
	if (!len_lis_list)
	{
		free(array_a);
		return (NULL);
	}
	len_lis_list = calc_lis_lens(array_a, len_lis_list, argc - 1);
	max_len = find_max_len(len_lis_list, argc - 1);
	lis = create_lis(array_a, len_lis_list, argc - 1, max_len);
	*lis_len = max_len;
	free(array_a);
	free(len_lis_list);
	return (lis);
}
