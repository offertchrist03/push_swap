/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:14:45 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/20 21:25:25 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return (0);
	exec_stack_head_node_push(stack_b, stack_a);
	return (1);
}

int	exec_rb(t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	exec_stack_first_to_last(stack_b);
	return (1);
}

int	exec_rrb(t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	exec_stack_last_to_first(stack_b);
	return (1);
}

int	exec_sb(t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	exec_head_content_swap(stack_b);
	return (1);
}
