/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:39:04 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/26 09:09:04 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_nothing_on_void(void *content)
{
	(void)content;
}

void	del_node_content(void *content)
{
	if (!content)
		return ;
	if (ft_strlen(content) > 0)
		ft_bzero(content, ft_strlen(content));
}

t_list	*list_pop_first(t_list **lst)
{
	t_list	*first;

	if (!lst || !*lst)
		return (NULL);
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	return (first);
}

t_list	*list_pop_last(t_list **lst)
{
	t_list	*curr;
	t_list	*last;
	int		i;
	int		size;

	if (!lst || !*lst)
		return (NULL);
	curr = *lst;
	last = ft_lstlast(curr);
	size = ft_lstsize(curr);
	i = 0;
	while (curr->next && i < (size - 2))
	{
		curr = curr->next;
		i++;
	}
	curr->next = NULL;
	return (last);
}
