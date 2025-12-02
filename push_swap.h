/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:56:46 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/01 18:25:41 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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


t_list				*create_new_node(int data);
t_list				*create_stack(int argc, char **argv);
void				print_nodes(t_list *head);
long				ft_atol(const char *nptr);
t_list				*sa(t_list *first_node, t_list *second_node, int flag);
t_list				*sb(t_list *first_node, t_list *second_node, int flag);
void				ss(t_list *a_1, t_list *a_2, t_list *b_1, t_list *b_2);
t_list				*pb(t_list **stack_a, t_list *stack_b);
t_list				*pa(t_list *stack_a, t_list **stack_b);
t_list				*ra(t_list *stack_a, int flag);
t_list				*rb(t_list *stack_b, int flag);
void				rr(t_list **stack_a, t_list **stack_b);
t_list				*end_of_stack(t_list *stack);
t_list				*bef_end_of_stack(t_list *stack);
void				rra(t_list **stack_a, int flag);
void				rrb(t_list **stack_b, int flag);
void				rrr(t_list **stack_a, t_list **stack_b);
void				check_args(int argc, char **argv);
int					is_duplicate(int *unique_nbrs, int num, int len);
int					is_number(char *arg);
int					is_int_range(long nbr);
void				error_exit(void);
int					*convert_array(t_list *stack, int argc);
int					*len_lis_min(int *array_a, int argc);
int					*calc_lis_lens(int *arr, int *len_lis, int n);
int					find_max_len(int *len_lis, int n);
int					*create_lis(int *array_a, int *len_lis, int n, int max_len);
int					*find_lis(t_list *stack_a, int argc, int *lis_len);
t_list              *push_out_lis(int *lis, t_list **stack_a, int argc, int lis_len);
int					stack_len(t_list *stack);
int					*find_cost_list_b(t_list *stack_b);
int					*find_cost_list_a(t_list *stack_a, t_list *stack_b);
int					find_best_index(int *total_costs, int size);
int					find_min_index(t_list *stack);
int					*calculate_total_cost(int *cost_to_a, int *cost_to_b,
						int size);
void				lis_sort(t_list **stack_a, t_list **stack_b, int argc);
void				edit_sorted_stack(t_list **stack_a);

#endif
