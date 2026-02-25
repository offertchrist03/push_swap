/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:42:38 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:47 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*lst_get_max(t_list *lst)
{
	void	*max;

	if (!lst)
		return (NULL);
	max = ft_strdup(lst->content);
	while (lst)
	{
		if (compare_numbers(max, lst->content) < 0)
		{
			free(max);
			max = ft_strdup(lst->content);
		}
		lst = lst->next;
	}
	return (max);
}

void	*lst_get_min(t_list *lst)
{
	void	*min;

	if (!lst)
		return (NULL);
	min = ft_strdup(lst->content);
	while (lst)
	{
		if (compare_numbers(min, lst->content) > 0)
		{
			free(min);
			min = ft_strdup(lst->content);
		}
		lst = lst->next;
	}
	return (min);
}

int	is_content_in_half(void *content, t_list *stack)
{
	int	i;
	int	stack_len;
	int	half;

	if (!content || !stack)
		return (-1);
	i = 0;
	stack_len = ft_lstsize(stack);
	half = stack_len / 2;
	if ((stack_len % 2) > 0)
		half++;
	while (i < (half))
	{
		if (compare_numbers(content, stack->content) == 0)
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}
