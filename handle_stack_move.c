/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:21:02 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 16:18:46 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	head_content_swap(t_list **lst, char *move, t_list **move_list)
{
	t_list	*dest;
	t_list	*src;
	void	*temp;

	if (!lst || !move)
		return (0);
	dest = *lst;
	src = dest->next;
	if (!dest || !src)
		return (0);
	temp = dest->content;
	dest->content = src->content;
	src->content = temp;
	move_register(move_list, move);
	return (1);
}

int	stack_head_node_push(t_list **dest, t_list **src, char *move,
		t_list **move_list)
{
	t_list	*first_src;

	if (!src || !*src || !move)
		return (0);
	if (ft_lstsize(*src) < 1)
		return (0);
	first_src = list_pop_first(src);
	ft_lstadd_front(dest, first_src);
	move_register(move_list, move);
	return (1);
}

int	stack_last_to_first(t_list **lst, char *move, t_list **move_list)
{
	t_list	*last;

	if (!lst || !*lst || !move)
		return (0);
	if (ft_lstsize(*lst) <= 1)
		return (0);
	last = list_pop_last(lst);
	ft_lstadd_front(lst, last);
	move_register(move_list, move);
	return (1);
}

int	stack_first_to_last(t_list **lst, char *move, t_list **move_list)
{
	t_list	*first;

	if (!lst || !*lst || !move)
		return (0);
	if (ft_lstsize(*lst) <= 1)
		return (0);
	first = list_pop_first(lst);
	ft_lstadd_back(lst, first);
	move_register(move_list, move);
	return (1);
}
