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

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*create_new_node(int data, t_list *head);
t_list	*uptade_head_node(t_list *head, t_list *new_node);
void	print_nodes(t_list	*head);
int		ft_atoi(const char *nptr);
t_list	*sa(t_list *first_node, t_list *second_node);
t_list	*sb(t_list *first_node, t_list *second_node);
void	ss(t_list *a_1, t_list *a_2, t_list *b_1, t_list *b_2);
t_list	*pb(t_list **stack_a, t_list *stack_b);
t_list	*pa(t_list *stack_a, t_list **stack_b);

#endif