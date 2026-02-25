/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:53:08 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/18 05:28:50 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ERROR_H
# define FT_PRINTF_ERROR_H

# include "../src/ft_printf.h"
# include <stdarg.h>

int	ft_printf_error(const char *format, ...);
int	handle_format_error(char specifer, va_list args);

#endif
