/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:43:25 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/22 17:54:10 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] <= '9' && nptr[i] >= '0'))
	{
		result *= 10;
		result = result + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
