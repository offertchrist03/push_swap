/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:14:04 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:47 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*future;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		future = current->next;
		ft_lstdelone(current, del);
		current = future;
	}
	*lst = NULL;
}
