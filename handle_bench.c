/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:50:44 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/20 19:05:30 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_move(t_list *move_list, char *move)
{
	int	count;

	if (!move_list || !move)
		return (0);
	count = 0;
	while (move_list != NULL)
	{
		if (compare(move_list->content, move) == 0)
			count++;
		move_list = move_list->next;
	}
	return (count);
}

static int	print_move_count(t_list *move_list)
{
	if (!move_list)
		return (0);
	ft_printf_error("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n",
		count_move(move_list, "sa"), count_move(move_list, "sb"),
		count_move(move_list, "ss"), count_move(move_list, "pa"),
		count_move(move_list, "pb"));
	ft_printf_error("[bench] ra:\t%d\trb:\t%d\trr:\t%d\t"
		"rra:\t%d\trrb:\t%d\trrr:\t%d\n", count_move(move_list, "ra"),
		count_move(move_list, "rb"), count_move(move_list, "rr"),
		count_move(move_list, "rra"), count_move(move_list, "rrb"),
		count_move(move_list, "rrr"));
	return (1);
}

int	show_bench(t_list *move_list, int disorder, int strategy)
{
	char	*str_strategy;

	if (!move_list || disorder < 0)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	str_strategy = print_strategy(strategy, disorder);
	ft_printf_error("[bench] disorder:\t");
	print_disorder(disorder);
	ft_printstr("%\n", 2);
	ft_printf_error("[bench] strategy:\t%s\n", str_strategy);
	ft_printf_error("[bench] total_ops:\t%d\n", ft_lstsize(move_list));
	print_move_count(move_list);
	free(str_strategy);
	return (1);
}
