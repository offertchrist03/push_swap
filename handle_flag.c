/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 07:26:01 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/26 16:20:29 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_flag(char *str)
{
	if (compare(str, "--bench") == 0 || compare(str, "--simple") == 0
		|| compare(str, "--medium") == 0 || compare(str, "--complex") == 0
		|| compare(str, "--adaptive") == 0)
		return (1);
	return (0);
}

int	is_flag(char *str)
{
	int	i;

	if (!(str[0] == '-' && str[1] == '-'))
		return (0);
	i = 2;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
		{
			if (!(str[i] == '-'
					&& ft_isalpha(str[i - 1])
					&& ft_isalpha(str[i + 1])))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_for_flag(int argc, char **argv, char *flag)
{
	int	i;
	int	count;

	if (argc <= 0)
		return (0);
	i = 0;
	count = 0;
	while (argv[i])
	{
		if (compare(argv[i], flag) == 0)
			count++;
		i++;
	}
	return (count);
}

int	count_flag(int argc, char **argv)
{
	int	flag;
	int	i;

	if (!argv)
		return (-1);
	flag = 0;
	i = 0;
	while (argv[i] && i < argc)
	{
		if (is_valid_flag(argv[i]) > 0
			&& compare(argv[i], "--bench") != 0)
			flag++;
		if (is_flag(argv[i]) > 0 && is_valid_flag(argv[i]) <= 0)
			return (-1);
		i++;
	}
	return (flag);
}

int	skip_flag(int argc, char **argv)
{
	int	i;
	int	count;

	if (!argv || argc <= 0)
		return (0);
	i = 0;
	count = 0;
	while (argv[i] && i < argc)
	{
		if (is_flag(argv[i]))
			count++;
		i++;
	}
	return (count);
}
