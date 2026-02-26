/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:03:32 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/26 11:07:28 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_disorder(t_list *stack)
{
	int	disorder;

	disorder = 0;
	if (!stack)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	disorder = compute_disorder(stack);
	if (disorder == 0)
	{
		ft_lstclear(&stack, (void *)del_node_content);
		stack = NULL;
		return (0);
	}
	return (disorder);
}

static int	manage_solver(t_list **stack, t_list **move_list, int disorder,
		int strategy)
{
	int	res;

	if (strategy == 1)
		*move_list = solver_simple(stack);
	else if (strategy == 2)
		*move_list = solver_medium(stack);
	else if (strategy == 3)
		*move_list = solver_complex(stack);
	else
	{
		if (ft_lstsize(*stack) <= 5)
			*move_list = solver_minim(stack);
		else
		{
			strategy = adapt_strategy(disorder);
			res = manage_solver(stack, move_list, disorder, strategy);
			return (res);
		}
	}
	if (!move_list)
		return (0);
	return (1);
}

int	solver_main(int argc, char **argv, int has_flag_bench, int strategy)
{
	t_list	*stack;
	t_list	*move_list;
	int		disorder;

	if (argc < 1)
		return (0);
	stack = NULL;
	stack = gen_stack((argc), argv);
	disorder = get_disorder(stack);
	if (disorder <= 0)
	{
		if (!!split_all_arg(argc, argv))
			ft_lstclear(&stack, free);
		if (has_flag_bench)
			show_bench(NULL, disorder, strategy);
		return (0);
	}
	manage_solver(&stack, &move_list, disorder, strategy);
	if (manage_solver <= 0)
		return (-1);
	print_move_list(move_list);
	if (has_flag_bench)
		show_bench(move_list, disorder, strategy);
	ft_lstclear(&move_list, do_nothing_on_void);
	return (0);
}
