/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:40:48 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:10:31 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int num, int fd)
{
	int		count;
	char	*number;

	count = 0;
	number = ft_itoa(num);
	count += ft_printstr(number, fd);
	free(number);
	return (count);
}
