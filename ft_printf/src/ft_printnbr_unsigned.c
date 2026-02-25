/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:29:32 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:10:31 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_unsigned(unsigned long num, int fd)
{
	int		count;
	char	*number;

	count = 0;
	number = ft_itoa_unsigned(num);
	count += ft_printstr(number, fd);
	free(number);
	return (count);
}
