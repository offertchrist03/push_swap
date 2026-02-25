/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:06:16 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/20 12:06:28 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_sqrt(int num)
{
	int	i;

	if (num <= 0)
		return (0);
	i = 1;
	while (i < (num / 2))
	{
		if ((i * i) == num)
			return (i);
		i++;
	}
	return (-1);
}

int	find_sequence(int num)
{
	int	i;
	int	seq;

	seq = find_sqrt(num);
	i = 1;
	while (seq == -1)
	{
		seq = find_sqrt(num + i);
		i++;
	}
	return (seq);
}

int	is_index_in_half(int index, t_list *stack)
{
	int	i;
	int	stack_len;
	int	half;

	if (!stack)
		return (-1);
	i = 0;
	stack_len = ft_lstsize(stack);
	half = stack_len / 2;
	if ((stack_len % 2) > 0)
		half++;
	while (i < (half))
	{
		if (index == ((int *)(stack->content))[1])
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}
