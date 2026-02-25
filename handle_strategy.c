/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:12:04 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/18 08:43:20 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_strategy(char *arg)
{
	if (compare(arg, "--simple") == 0)
		return (1);
	else if (compare(arg, "--medium") == 0)
		return (2);
	else if (compare(arg, "--complex") == 0)
		return (3);
	else if (compare(arg, "--adaptive") == 0)
		return (0);
	return (0);
}

int	adapt_strategy(int disorder)
{
	if (disorder < (0.2 * 10000))
		return (1);
	else if (disorder < (0.5 * 10000))
		return (2);
	else
		return (3);
}

int	set_strategy(int argc, char **argv)
{
	int	i;
	int	strategy;

	strategy = 0;
	if (!(argv && argv[0]) || argc <= 0)
		return (0);
	i = 0;
	while (i < argc && argv[i])
	{
		strategy = correct_strategy(argv[i]);
		if (strategy > 0)
			return (strategy);
		i++;
	}
	return (0);
}
