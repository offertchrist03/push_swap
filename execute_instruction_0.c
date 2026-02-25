/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_0.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:02:01 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/20 21:27:12 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	exec_stack_head_node_push(stack_a, stack_b);
	return (1);
}

int	exec_ra(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);
	exec_stack_first_to_last(stack_a);
	return (1);
}

int	exec_rra(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);
	exec_stack_last_to_first(stack_a);
	return (1);
}

int	exec_sa(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);
	exec_head_content_swap(stack_a);
	return (1);
}
