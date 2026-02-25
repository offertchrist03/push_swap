/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:55:59 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:10:31 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr, int fd)
{
	int				count;
	unsigned long	addr;
	char			*buff_addr;

	count = 0;
	if (!ptr)
		return (ft_printstr("(nil)", fd));
	count += ft_printstr("0x", fd);
	addr = (unsigned long)ptr;
	buff_addr = ft_itoh(addr);
	if (!buff_addr)
		return (count);
	count += ft_printstr(buff_addr, fd);
	free(buff_addr);
	return (count);
}
