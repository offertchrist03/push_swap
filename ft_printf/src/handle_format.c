/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:20:43 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/03 20:58:50 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char specifer, va_list args)
{
	int	count;

	count = 0;
	if (specifer == 'c')
		count = ft_printchar((char)va_arg(args, int), 1);
	else if (specifer == 's')
		count = ft_printstr((char *)va_arg(args, char *), 1);
	else if (specifer == 'd' || specifer == 'i')
		count = ft_printnbr((long)va_arg(args, int), 1);
	else if (specifer == 'u')
		count = ft_printnbr_unsigned((unsigned long)va_arg(args, unsigned int),
				1);
	else if (specifer == 'x')
		count = ft_printhex((unsigned long)va_arg(args, unsigned int), 0, 1);
	else if (specifer == 'X')
		count = ft_printhex((unsigned long)va_arg(args, unsigned int), 1, 1);
	else if (specifer == 'p')
		count = ft_printptr((void *)va_arg(args, void *), 1);
	else if (specifer == '%')
		count = ft_printchar('%', 1);
	return (count);
}
