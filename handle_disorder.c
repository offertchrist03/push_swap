/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:12:20 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/20 16:09:08 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(int disorder)
{
	int	integer_part;
	int	fractional_part;

	if (disorder < 0)
		disorder = 0;
	integer_part = disorder / 100;
	fractional_part = disorder % 100;
	ft_printnbr(integer_part, 2);
	ft_printchar('.', 2);
	if (fractional_part < 10)
		ft_printnbr(0, 2);
	ft_printnbr(fractional_part, 2);
}

int	compute_disorder(t_list *stack)
{
	double	res;
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < ft_lstsize(stack))
	{
		j = i + 1;
		while (j < ft_lstsize(stack))
		{
			total_pairs++;
			if (compare_numbers(stack_at(stack, i)->content, stack_at(stack,
						j)->content) >= 0)
				mistakes++;
			j++;
		}
		i++;
	}
	res = (mistakes / total_pairs) * 10000;
	return (res);
}
