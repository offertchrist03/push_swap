/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:07:13 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 16:18:50 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_at(t_list *lst, int index)
{
	t_list	*curr;
	int		i;

	if (!lst || index < 0)
		return (NULL);
	i = 0;
	curr = lst;
	while (curr)
	{
		if (i == index)
			break ;
		i++;
		curr = curr->next;
	}
	return (curr);
}

t_list	*gen_stack(int size, char **numbers)
{
	t_list	*lst;
	t_list	*new_lst;
	int		i;

	if (!numbers || !*numbers)
		return (NULL);
	i = 0;
	lst = NULL;
	while (i < size && numbers[i])
	{
		if (!is_flag(numbers[i]))
		{
			new_lst = ft_lstnew(numbers[i]);
			if (!new_lst)
				return (NULL);
			ft_lstadd_back(&lst, new_lst);
		}
		i++;
	}
	return (lst);
}
