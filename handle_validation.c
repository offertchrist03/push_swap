/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:24:57 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:49 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_numbers(int argc, char **argv)
{
	int	i;

	if (!(argv && argv[0]) || argc <= 0)
		return (-1);
	i = 0;
	while (i < argc && argv[i])
	{
		if (!(is_num(argv[i]) || is_flag(argv[i])))
			return (-1);
		i++;
	}
	return (1);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	if (!argv || !*argv || !(argc > 1))
		return (-1);
	i = 0;
	while (i < argc && argv[i])
	{
		j = 0;
		while (j < argc && argv[j])
		{
			if (!is_flag(argv[i]) && !is_flag(argv[j]))
				if (i != j && (compare(argv[i], argv[j]) == 0))
					return (1);
			j++;
		}
		i++;
	}
	return (-1);
}

int	valid_args(int argc, char **argv)
{
	int	n_flag;

	if (argc < 1)
		return (0);
	n_flag = count_flag((argc), argv);
	if (n_flag == -1 || n_flag > 1)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	if (is_all_numbers((argc), argv) <= 0 || check_double((argc), argv) == 1)
	{
		ft_printf_error("Error\n");
		return (-1);
	}
	return (1);
}
