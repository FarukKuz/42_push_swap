/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:17:25 by fakuz             #+#    #+#             */
/*   Updated: 2025/07/11 13:53:38 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	if ((unsigned char)c == 0)
		return ((char *)s + i + 1);
	while (s[i] != (unsigned char)c && i >= 0)
		i--;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}
