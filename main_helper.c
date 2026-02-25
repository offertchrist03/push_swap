/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:28:34 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:46:55 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_register(t_list **move_list, char *move)
{
	t_list	*new_move;

	if (!move)
	{
		ft_printf("Error\n");
		return (-1);
	}
	new_move = ft_lstnew(move);
	ft_lstadd_back(move_list, new_move);
	return (1);
}

void	print_move_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}
