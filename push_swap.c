/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:31:44 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/26 16:32:29 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	one_arg(int argc, char **argv)
{
	if (argc <= 2)
	{
		if (!argv[1])
			return (0);
		if (argc == 2 && is_splitable_arg(argv[1]))
			return (1);
		if (ft_strlen(argv[1]) <= 0
			|| !is_num(argv[1]))
		{
			ft_printf_error("Error\n");
			return (-1);
		}
		return (0);
	}
	return (1);
}

static int	main_split(char **splited)
{
	int		is_valid_args;
	int		has_flag_bench;
	int		strategy;
	int		solved;

	if (!splited)
		return (-1);
	strategy = set_strategy((split_len(splited)), splited);
	has_flag_bench = check_for_flag((split_len(splited)), splited, "--bench");
	if (split_len(splited) <= 1)
	{
		free_split(splited, split_len(splited));
		return (0);
	}
	is_valid_args = valid_args(split_len(splited), splited);
	if (!(is_valid_args == 1))
	{
		free_split(splited, split_len(splited));
		return (is_valid_args);
	}
	solved = solver_main(split_len(splited), splited, has_flag_bench, strategy);
	free_split(splited, split_len(splited));
	return (solved);
}

int	main(int argc, char **argv)
{
	int		is_valid_args;
	int		has_flag_bench;
	int		strategy;
	int		solved;
	char	**splited;

	is_valid_args = one_arg(argc, argv);
	if (is_valid_args <= 0)
		return (is_valid_args);
	splited = split_all_arg((argc - 1), &argv[1]);
	if (splited || is_splitable_arg(argv[1]))
	{
		if (!splited)
			ft_printf_error("Error\n");
		solved = main_split(splited);
		return (solved);
	}
	strategy = set_strategy((argc), argv);
	has_flag_bench = check_for_flag((argc), argv, "--bench");
	is_valid_args = valid_args((argc - 1), &argv[1]);
	if (!(is_valid_args == 1))
		return (is_valid_args);
	solved = solver_main((argc - 1), &argv[1], has_flag_bench, strategy);
	return (solved);
}
