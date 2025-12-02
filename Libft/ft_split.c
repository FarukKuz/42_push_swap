/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:56:01 by fakuz             #+#    #+#             */
/*   Updated: 2025/07/10 13:11:59 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *str, char c)
{
	int	counter;
	int	i;
	int	flag;

	counter = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != c && !flag)
		{
			counter++;
			flag = 1;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (counter);
}

static char	*ft_create_words(const char *str, char c, int i)
{
	char			*dest;
	size_t			len;
	unsigned int	start;

	len = 0;
	start = i;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	dest = ft_substr(str, start, len);
	return (dest);
}

static void	ft_free_memory(char **strs, int index)
{
	while (index >= 0)
	{
		free(strs[index]);
		index--;
	}
	free (strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**dest;
	int		index;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!dest)
		return (NULL);
	index = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			dest[index++] = ft_create_words(s, c, i);
			if (!dest)
				return (ft_free_memory(dest, index - 1), NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		if (!s[i])
			break ;
		i++;
	}
	dest[index] = NULL;
	return (dest);
}
