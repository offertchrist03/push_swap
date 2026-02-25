/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:32:03 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/19 10:41:12 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

static int	in_set(char c)
{
	const char	*set;
	int			i;

	set = "csdiuxXp%";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	do_printf(const char *format, int format_i, va_list format_arg)
{
	int	count;

	count = 0;
	while (format[format_i])
	{
		if (format[format_i] == '%')
		{
			if (format[format_i + 1] && in_set(format[format_i + 1]))
			{
				count += handle_format_error(format[format_i + 1], format_arg);
				format_i += 2;
				continue ;
			}
			else if (!ft_isprint(format[format_i + 1]))
			{
				va_end(format_arg);
				return (-1);
			}
		}
		count += ft_printchar(format[format_i], 2);
		format_i++;
	}
	return (count);
}

int	ft_printf_error(const char *format, ...)
{
	int		format_i;
	int		count;
	va_list	format_arg;

	if (!format)
		return (-1);
	format_i = 0;
	count = 0;
	va_start(format_arg, format);
	count += do_printf(format, format_i, format_arg);
	if (count == -1)
		return (-1);
	va_end(format_arg);
	return (count);
}
