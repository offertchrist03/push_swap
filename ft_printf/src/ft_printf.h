/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:53:08 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:08:29 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "../utils/utils.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_format(char specifer, va_list args);

int	ft_printchar(char c, int fd);
int	ft_printstr(char *s, int fd);
int	ft_printptr(void *ptr, int fd);
int	ft_printnbr(long int num, int fd);
int	ft_printnbr_unsigned(unsigned long num, int fd);
int	ft_printhex(unsigned long num, int is_uppercase, int fd);

#endif
