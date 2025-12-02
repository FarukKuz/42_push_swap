/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:07:09 by fakuz             #+#    #+#             */
/*   Updated: 2025/07/11 11:36:36 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(n);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	dest[len] = '\0';
	len--;
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
	}
	while (n > 0)
	{
		dest[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (dest);
}
