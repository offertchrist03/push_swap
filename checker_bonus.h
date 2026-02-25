/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:10:30 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/21 00:09:14 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"

int	exec_head_content_swap(t_list **lst);
int	exec_stack_head_node_push(t_list **dest, t_list **src);
int	exec_stack_last_to_first(t_list **lst);
int	exec_stack_first_to_last(t_list **lst);

int	exec_pa(t_list **stack_a, t_list **stack_b);
int	exec_ra(t_list **stack_a);
int	exec_rra(t_list **stack_a);
int	exec_sa(t_list **stack_a);

int	exec_pb(t_list **stack_a, t_list **stack_b);
int	exec_rb(t_list **stack_b);
int	exec_rrb(t_list **stack_b);
int	exec_sb(t_list **stack_b);

int	exec_rr(t_list **stack_a, t_list **stack_b);
int	exec_rrr(t_list **stack_a, t_list **stack_b);
int	exec_ss(t_list **stack_a, t_list **stack_b);

#endif
