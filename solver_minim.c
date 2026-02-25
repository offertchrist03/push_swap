/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_minim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:04:23 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/25 08:40:21 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_two(t_list **stack_a, t_list **move_list)
{
	int	min;

	min = lst_get_min_index(*stack_a);
	if (((int *)(stack_at(*stack_a, 0)->content))[1] != min)
		stack_first_to_last(stack_a, "ra", move_list);
	return (1);
}

static int	sort_three(t_list **stack_a, t_list **move_list)
{
	int	max;
	int	min;

	min = lst_get_min_index(*stack_a);
	max = lst_get_max_index(*stack_a);
	if (((int *)(stack_at(*stack_a, 0)->content))[1] == max)
		stack_first_to_last(stack_a, "ra", move_list);
	else if (((int *)(stack_at(*stack_a, 1)->content))[1] == max)
		stack_last_to_first(stack_a, "rra", move_list);
	if (((int *)(stack_at(*stack_a, 0)->content))[1] != min)
		head_content_swap(stack_a, "sa", move_list);
	return (1);
}

static int	sort_five(t_list **stack_a, t_list **stack_b, t_list **move_list)
{
	int	max_b;
	int	min_a;
	int	max_a;

	while (ft_lstsize(*stack_a) > 3)
		stack_head_node_push(stack_b, stack_a, "pb", move_list);
	sort_three(stack_a, move_list);
	min_a = lst_get_min_index(*stack_a);
	max_b = lst_get_max_index(*stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{
		while (((int *)(stack_at(*stack_b, 0)->content))[1] != max_b)
			stack_first_to_last(stack_b, "rb", move_list);
		while (((int *)(stack_at(*stack_a, 0)->content))[1] != min_a)
			stack_first_to_last(stack_a, "ra", move_list);
		max_a = lst_get_max_index(*stack_a);
		max_b = lst_get_max_index(*stack_b);
		if (max_a < max_b)
			stack_head_node_push(stack_a, stack_b, "pa", move_list);
		else
		{
			while (((int *)(stack_at(*stack_a, 0)->content))[1] < max_b)
				stack_first_to_last(stack_a, "ra", move_list);
			stack_head_node_push(stack_a, stack_b, "pa", move_list);
		}
		max_b = lst_get_max_index(*stack_b);
	}
	min_a = lst_get_min_index(*stack_a);
	while (((int *)(stack_at(*stack_a, 0)->content))[1] != min_a)
		stack_last_to_first(stack_a, "rra", move_list);
	return (1);
}

t_list	*solver_minim(t_list **stack_a)
{
	t_list	*move_list;
	t_list	*stack_b;
	int		list_size;

	stack_b = NULL;
	move_list = NULL;
	if (!stack_a)
		return (move_list);
	list_size = ft_lstsize(*stack_a);
	*stack_a = gen_stack_index(stack_a);
	if (list_size == 2)
		sort_two(stack_a, &move_list);
	else if (list_size == 3)
		sort_three(stack_a, &move_list);
	else
		sort_five(stack_a, &stack_b, &move_list);
	ft_lstclear(stack_a, free);
	return (move_list);
}
