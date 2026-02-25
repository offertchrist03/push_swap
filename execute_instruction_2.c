/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:02:05 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/21 00:09:33 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_rr(t_list **stack_a, t_list **stack_b)
{
	exec_ra(stack_a);
	exec_rb(stack_b);
	return (1);
}

int	exec_rrr(t_list **stack_a, t_list **stack_b)
{
	exec_ra(stack_a);
	exec_rb(stack_b);
	return (1);
}

int	exec_ss(t_list **stack_a, t_list **stack_b)
{
	exec_ra(stack_a);
	exec_rb(stack_b);
	return (1);
}
