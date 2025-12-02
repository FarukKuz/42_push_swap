/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:40:32 by fakuz             #+#    #+#             */
/*   Updated: 2025/07/10 16:40:47 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != 0)
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (0);
	dest = ft_memcpy(dest, s1 + start, end - start);
	dest[end - start] = 0;
	return (dest);
}
