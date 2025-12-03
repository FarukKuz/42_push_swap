/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:10:48 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 18:24:22 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static char	*join_args(int argc, char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = result;
		result = ft_strjoin(result, argv[i]);
		free(temp);
		if (i < argc - 1)
		{
			temp = result;
			result = ft_strjoin(result, " ");
			free(temp);
		}
		i++;
	}
	return (result);
}

char	**split_args(int argc, char **argv)
{
	char	*joined;
	char	**args;

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}
