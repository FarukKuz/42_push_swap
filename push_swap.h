/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:56:46 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/03 19:28:24 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_lis_data
{
	int				*lis;
	int				lis_len;
}					t_lis_data;

t_list		*return_stack(int argc, char **argv);
void		free_args(char **args);
int			count_args(char **args);
char		**split_args(int argc, char **argv);
long		ft_atol(const char *nptr);
t_list		*sa(t_list *first_node, t_list *second_node, int flag);
t_list		*sb(t_list *first_node, t_list *second_node, int flag);
void		ss(t_list *a_1, t_list *a_2, t_list *b_1, t_list *b_2);
t_list		*pb(t_list **stack_a, t_list *stack_b);
t_list		*pa(t_list *stack_a, t_list **stack_b);
t_list		*ra(t_list *stack_a, int flag);
t_list		*rb(t_list *stack_b, int flag);
void		rr(t_list **stack_a, t_list **stack_b);
t_list		*end_of_stack(t_list *stack);
t_list		*bef_end_of_stack(t_list *stack);
void		rra(t_list **stack_a, int flag);
void		rrb(t_list **stack_b, int flag);
void		rrr(t_list **stack_a, t_list **stack_b);
void		check_args(int argc, char **argv);
int			is_duplicate(int *unique_nbrs, int num, int len);
int			is_number(char *arg);
int			is_int_range(long nbr);
void		error_exit(int *unique_nbrs);
int			*convert_array(t_list *stack, int argc);
int			*find_lis(t_list *stack_a, int argc, int *lis_len);
int			stack_len(t_list *stack);
void		free_stack(t_list *stack);
int			*find_cost_list_b(t_list *stack_b);
int			*find_cost_list_a(t_list *stack_a, t_list *stack_b);
int			find_best_index(int *total_costs, int size);
int			find_min_index(t_list *stack);
int			*calculate_total_cost(int *cost_a, int *cost_b, int size);
void		lis_sort(t_list **stack_a, t_list **stack_b, int argc);
t_list		*prepare_stack_b(t_list **stack_a, int argc);
void		three_sort(t_list **stack);

#endif
