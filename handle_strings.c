/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:43:01 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/19 09:59:06 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*print_strategy_name(int strategy)
{
	char	*str;

	if (strategy == 1)
		str = ("Simple / ");
	else if (strategy == 2)
		str = ("Medium / ");
	else if (strategy == 3)
		str = ("Complex / ");
	else if (strategy == 0)
		str = ("Adaptive / ");
	else
		str = ("unknown / ");
	return (str);
}

static char	*print_strategy_complexity(int strategy, int disorder)
{
	char	*str;

	if (strategy <= 0 || strategy > 3)
		strategy = adapt_strategy(disorder);
	if (strategy == 1)
		str = ("O(n^2)");
	else if (strategy == 2)
		str = ("O(n√n)");
	else if (strategy == 3)
		str = ("O(n log n)");
	else
		str = ("unknown");
	return (str);
}

char	*print_strategy(int strategy, int disorder)
{
	char	*name;
	char	*complexity;
	char	*final_str;
	size_t	final_len;

	name = print_strategy_name(strategy);
	if (!name)
		return (NULL);
	complexity = print_strategy_complexity(strategy, disorder);
	if (!complexity)
		return (NULL);
	final_len = ft_strlen(name) + ft_strlen(complexity);
	final_str = ft_calloc((final_len + 1), sizeof(char));
	if (!final_str)
		return (NULL);
	ft_strlcat(final_str, name, ft_strlen(name) + 1);
	ft_strlcat(final_str, complexity, final_len + ft_strlen(complexity));
	return (final_str);
}
