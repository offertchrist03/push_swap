/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_move.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:21:02 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:57 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_head_content_swap(t_list **lst)
{
	t_list	*dest;
	t_list	*src;
	void	*temp;

	if (!lst)
		return (0);
	dest = *lst;
	src = dest->next;
	if (!dest || !src)
		return (0);
	temp = dest->content;
	dest->content = src->content;
	src->content = temp;
	return (1);
}

int	exec_stack_head_node_push(t_list **dest, t_list **src)
{
	t_list	*first_src;

	if (!src || !*src)
		return (0);
	if (ft_lstsize(*src) < 1)
		return (0);
	first_src = list_pop_first(src);
	ft_lstadd_front(dest, first_src);
	return (1);
}

int	exec_stack_last_to_first(t_list **lst)
{
	t_list	*last;

	if (!lst || !*lst)
		return (0);
	if (ft_lstsize(*lst) <= 1)
		return (0);
	last = list_pop_last(lst);
	ft_lstadd_front(lst, last);
	return (1);
}

int	exec_stack_first_to_last(t_list **lst)
{
	t_list	*first;

	if (!lst || !*lst)
		return (0);
	if (ft_lstsize(*lst) <= 1)
		return (0);
	first = list_pop_first(lst);
	ft_lstadd_back(lst, first);
	return (1);
}
