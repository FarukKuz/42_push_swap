//
//  split_args.c
//  push_swap
//
//  Created by Faruk Kuz on 3.12.2025.
//

#include "push_swap.h"
#include "Libft/libft.h"

void    free_args(char **args)
{
    int    i;

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

int    count_args(char **args)
{
    int    count;

    count = 0;
    while (args[count])
    {
        printf("%s\n", args[count]);
        count++;
    }
    return (count);
}

static char    *join_args(int argc, char **argv)
{
    char    *result;
    char    *temp;
    int        i;

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

char    **split_args(int argc, char **argv)
{
    char    *joined;
    char    **args;

    joined = join_args(argc, argv);
    if (!joined)
        return (NULL);
    args = ft_split(joined, ' ');
    free(joined);
    return (args);
}
