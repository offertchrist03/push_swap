/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:05:10 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:45 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_get_max_index(t_list *lst)
{
	int	max;

	if (!lst)
		return (-1);
	max = ((int *)(lst->content))[1];
	while (lst)
	{
		if (max < ((int *)(lst->content))[1])
			max = ((int *)(lst->content))[1];
		lst = lst->next;
	}
	return (max);
}

int	lst_get_min_index(t_list *lst)
{
	int	min;

	if (!lst)
		return (-1);
	min = ((int *)(lst->content))[1];
	while (lst)
	{
		if (min > ((int *)(lst->content))[1])
			min = ((int *)(lst->content))[1];
		lst = lst->next;
	}
	return (min);
}

static int	*stack_content_re(void *content)
{
	int	*ints;

	ints = (int *)malloc(3 * sizeof(int));
	if (!ints)
		ints = NULL;
	ints[0] = ft_atoi(content);
	ints[1] = 0;
	return (ints);
}

static int	set_index_stack(t_list **stack)
{
	t_list	*curr;
	t_list	*deep;

	if (!stack || !*stack)
		return (0);
	curr = *stack;
	while (curr)
	{
		deep = curr->next;
		while (deep)
		{
			if (((int *)(curr->content))[0] > ((int *)(deep->content))[0])
				((int *)(curr->content))[1] += 1;
			else
				((int *)(deep->content))[1] += 1;
			deep = deep->next;
		}
		curr = curr->next;
	}
	return (1);
}

t_list	*gen_stack_index(t_list **stack)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*curr;
	int		*new_content;

	new_list = NULL;
	if (!stack || !*stack)
		return (NULL);
	curr = *stack;
	while (curr)
	{
		new_content = stack_content_re(curr->content);
		if (!new_content)
			return (NULL);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_list, new_node);
		curr = curr->next;
		if (!curr)
			break ;
	}
	set_index_stack(&new_list);
	ft_lstclear(stack, del_node_content);
	return (new_list);
}
