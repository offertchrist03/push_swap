/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:02:05 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:11 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	seq_into_b(t_list **stack_a, t_list **stack_b, t_list **move_list,
		int sequence)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		size--;
		stack_first_to_last(stack_a, "ra", move_list);
		if (((int *)(*stack_a)->content)[1] <= sequence)
			stack_head_node_push(stack_b, stack_a, "pb", move_list);
	}
	return (1);
}

static int	max_into_a(t_list **stack_a, t_list **stack_b, t_list **move_list)
{
	int	max;

	max = lst_get_max_index(*stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{
		if (is_index_in_half(max, *stack_b))
			stack_first_to_last(stack_b, "rb", move_list);
		else
			stack_last_to_first(stack_b, "rrb", move_list);
		if (((int *)(*stack_b)->content)[1] == max)
		{
			stack_head_node_push(stack_a, stack_b, "pa", move_list);
			max = lst_get_max_index(*stack_b);
		}
	}
	return (1);
}

static int	chunck_sort(t_list **stack_a, t_list **stack_b, t_list **move_list)
{
	int	init_seq;
	int	seq;

	(void)stack_b;
	(void)move_list;
	if (!stack_a || !*stack_a)
		return (0);
	init_seq = find_sequence(ft_lstsize(*stack_a));
	seq = init_seq;
	while (ft_lstsize(*stack_a) > 0)
	{
		seq_into_b(stack_a, stack_b, move_list, seq);
		seq += init_seq;
	}
	max_into_a(stack_a, stack_b, move_list);
	return (1);
}

t_list	*solver_medium(t_list **stack_a)
{
	t_list	*move_list;
	t_list	*stack_b;

	stack_b = NULL;
	move_list = NULL;
	if (!stack_a)
		return (move_list);
	*stack_a = gen_stack_index(stack_a);
	chunck_sort(stack_a, &stack_b, &move_list);
	ft_lstclear(stack_a, free);
	return (move_list);
}
