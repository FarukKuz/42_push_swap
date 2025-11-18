/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:56:46 by fakuz             #+#    #+#             */
/*   Updated: 2025/11/06 17:23:13 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	                t_list;

t_list	    *create_new_node(int data, t_list *head);
t_list      *create_stack(int argc, char **argv);
void	    print_nodes(t_list	*head);
long	    ft_atol(const char *nptr);
t_list	    *sa(t_list *first_node, t_list *second_node, int flag);
t_list	    *sb(t_list *first_node, t_list *second_node, int flag);
void	    ss(t_list *a_1, t_list *a_2, t_list *b_1, t_list *b_2);
t_list	    *pb(t_list **stack_a, t_list *stack_b);
t_list	    *pa(t_list *stack_a, t_list **stack_b);
t_list      *ra(t_list *stack_a, int flag);
t_list      *rb(t_list *stack_b, int flag);
void        rr(t_list **stack_a, t_list **stack_b);
t_list      *end_of_stack(t_list *stack);
t_list      *bef_end_of_stack(t_list *stack);
void        rra(t_list **stack_a, int flag);
void        rrb(t_list **stack_b, int flag);
void        rrr(t_list **stack_a, t_list **stack_b);
void        check_args(int argc, char **argv);
int         is_duplicate(int *unique_nbrs, int num, int len);
int         is_number(char *arg);
int         is_int_range(long nbr);
void        error_exit(char *message);
int         *convert_array(t_list *stack, int argc);
int         *len_lis_min(int *array_a, int argc);
int         *calc_lis_lens(int *arr, int *len_lis, int n);
int         find_max_len(int *len_lis, int n);
int         *create_lis(int *array_a, int *len_lis, int n, int max_len);
int         *find_LIS(t_list *stack_a, int argc);

#endif
