/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:05:11 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/20 15:27:03 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	radix_10_sort(t_list **stack_a, t_list **stack_b,
		t_list **move_list)
{
	int	max_num;
	int	index[4];
	int	num;

	max_num = ft_lstsize(*stack_a) - 1;
	index[2] = 0;
	while ((max_num >> index[2]) != 0)
		index[2]++;
	index[0] = -1;
	while (++index[0] < index[2])
	{
		index[3] = ft_lstsize(*stack_a);
		index[1] = -1;
		while (++index[1] < index[3])
		{
			num = ((int *)((*stack_a)->content))[1];
			if ((num >> index[0] & 1) == 0)
				stack_head_node_push(stack_b, stack_a, "pb", move_list);
			else
				stack_first_to_last(stack_a, "ra", move_list);
		}
		while (ft_lstsize(*stack_b) > 0)
			stack_head_node_push(stack_a, stack_b, "pa", move_list);
	}
	return (1);
}

t_list	*solver_complex(t_list **stack_a)
{
	t_list	*move_list;
	t_list	*stack_b;

	stack_b = NULL;
	move_list = NULL;
	if (!stack_a)
		return (move_list);
	*stack_a = gen_stack_index(stack_a);
	radix_10_sort(stack_a, &stack_b, &move_list);
	ft_lstclear(stack_a, free);
	return (move_list);
}
