/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:04:23 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/20 16:14:50 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	into_b(t_list **stack_a, t_list **stack_b, t_list **move_list)
{
	int	min;
	int	min_a;

	min = lst_get_min_index(*stack_a);
	while (1)
	{
		if (is_index_in_half(min, *stack_a))
			stack_first_to_last(stack_a, "ra", move_list);
		else
			stack_last_to_first(stack_a, "rra", move_list);
		min_a = ((int *)(*stack_a)->content)[1];
		if (min == min_a)
		{
			stack_head_node_push(stack_b, stack_a, "pb", move_list);
			min = lst_get_min_index(*stack_a);
			if (ft_lstsize(*stack_a) <= 1)
				break ;
		}
	}
	return (1);
}

static int	insertion_sort(t_list **stack_a, t_list **stack_b,
		t_list **move_list)
{
	if (!stack_a || !*stack_a)
		return (0);
	into_b(stack_a, stack_b, move_list);
	while (1)
	{
		stack_head_node_push(stack_a, stack_b, "pa", move_list);
		if (ft_lstsize(*stack_b) <= 0)
			break ;
	}
	return (1);
}

t_list	*solver_simple(t_list **stack_a)
{
	t_list	*move_list;
	t_list	*stack_b;

	stack_b = NULL;
	move_list = NULL;
	if (!stack_a)
		return (move_list);
	*stack_a = gen_stack_index(stack_a);
	insertion_sort(stack_a, &stack_b, &move_list);
	ft_lstclear(stack_a, free);
	return (move_list);
}
