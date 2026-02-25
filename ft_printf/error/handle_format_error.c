/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:20:43 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/18 05:52:21 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

int	handle_format_error(char specifer, va_list args)
{
	int	count;

	count = 0;
	if (specifer == 'c')
		count = ft_printchar((char)va_arg(args, int), 2);
	else if (specifer == 's')
		count = ft_printstr((char *)va_arg(args, char *), 2);
	else if (specifer == 'd' || specifer == 'i')
		count = ft_printnbr((long)va_arg(args, int), 2);
	else if (specifer == 'u')
		count = ft_printnbr_unsigned((unsigned long)va_arg(args, unsigned int),
				2);
	else if (specifer == 'x')
		count = ft_printhex((unsigned long)va_arg(args, unsigned int), 0, 2);
	else if (specifer == 'X')
		count = ft_printhex((unsigned long)va_arg(args, unsigned int), 1, 2);
	else if (specifer == 'p')
		count = ft_printptr((void *)va_arg(args, void *), 2);
	else if (specifer == '%')
		count = ft_printchar('%', 2);
	return (count);
}
