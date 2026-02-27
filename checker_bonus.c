/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:51:42 by ainrakot          #+#    #+#             */
/*   Updated: 2026/02/27 14:10:37 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "push_swap.h"

static int	is_checker_valid(int argc, char **argv)
{
	int	is_valid_args;
	int	n_flag;
	int	has_flag_bench;

	if (is_splitable_arg(argv[0]) == 1)
		return (1);
	if (argc == 1 && !is_num(argv[0])
		&& is_splitable_arg(argv[0]) == -1)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	is_valid_args = valid_args((argc), argv);
	if (!(is_valid_args == 1))
		return (is_valid_args);
	n_flag = count_flag(argc, argv);
	has_flag_bench = check_for_flag(argc, argv, "--bench");
	if (n_flag > 0 || has_flag_bench)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	return (1);
}

static int	exec_move(t_list **stack_a, t_list **stack_b, char	*move)
{
	if (compare(move, "pa\n") == 0)
		exec_pa(stack_a, stack_b);
	else if (compare(move, "ra\n") == 0)
		exec_ra(stack_a);
	else if (compare(move, "rra\n") == 0)
		exec_rra(stack_a);
	else if (compare(move, "sa\n") == 0)
		exec_sa(stack_a);
	else if (compare(move, "pb\n") == 0)
		exec_pb(stack_a, stack_b);
	else if (compare(move, "rb\n") == 0)
		exec_rb(stack_b);
	else if (compare(move, "rrb\n") == 0)
		exec_rrb(stack_b);
	else if (compare(move, "sb\n") == 0)
		exec_sb(stack_b);
	else if (compare(move, "rr\n") == 0)
		exec_rr(stack_a, stack_b);
	else if (compare(move, "rrr\n") == 0)
		exec_rrr(stack_a, stack_b);
	else if (compare(move, "ss\n") == 0)
		exec_ss(stack_a, stack_b);
	else
		return (-1);
	return (1);
}

static int	read_and_exec(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		size;

	if (!stack_a || !*stack_a)
		return (-1);
	size = ft_lstsize(*stack_a) - 1;
	while (size > 0)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (exec_move(stack_a, stack_b, line) == -1)
			return (-1);
		free(line);
		size--;
	}
	line = get_next_line(0);
	if (line == NULL)
		return (1);
	free(line);
	return (0);
}

static int	show_ok_and_clear(t_list **stack_a, t_list **stack_b,
	char **splited, int is_valid)
{
	int		disorder;

	if (ft_lstsize(*stack_a) <= 1)
		disorder = 0;
	else
		disorder = compute_disorder(*stack_a);
	if (is_valid == -1)
		ft_printf_error("Error\n");
	else if (is_valid == 1 && ft_lstsize(*stack_b) == 0 && disorder <= 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(stack_a, del_node_content);
	if (stack_b && ft_lstsize(*stack_b) > 0)
		ft_lstclear(stack_b, del_node_content);
	if (splited && split_len(splited) > 0)
		free_split(splited, split_len(splited));
	return (1);
}

int	main(int argc, char **argv)
{
	char	**splited;
	t_list	*stack_a;
	t_list	*stack_b;
	int		is_valid;

	if (argc <= 1)
		return (0);
	is_valid = is_checker_valid((argc - 1), &argv[1]);
	if (is_valid != 1)
		return (is_valid);
	stack_a = NULL;
	stack_b = NULL;
	splited = split_all_arg((argc - 1), &argv[1]);
	if (splited)
		stack_a = gen_stack(split_len(splited), splited);
	else
		stack_a = gen_stack((argc - 1), &argv[1]);
	is_valid = read_and_exec(&stack_a, &stack_b);
	show_ok_and_clear(&stack_a, &stack_b, splited, is_valid);
	return (is_valid);
}
