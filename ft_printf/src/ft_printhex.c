/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:13:41 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/11 06:47:43 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long num, int is_uppercase, int fd)
{
	int		count;
	char	*hex;

	count = 0;
	hex = ft_itoh(num);
	if (!hex)
		return (0);
	if (is_uppercase)
		hex = str_uppercase(hex);
	count += ft_printstr(hex, fd);
	free(hex);
	return (count);
}
