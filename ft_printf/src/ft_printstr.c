/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:37:45 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:11:08 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s, int fd)
{
	size_t	i;
	size_t	len;
	int		count;

	count = 0;
	if (!s)
		return (ft_printstr("(null)", fd));
	i = 0;
	len = ft_strlen((const char *)s);
	while (i < len)
	{
		count += ft_printchar(s[i], fd);
		i++;
	}
	return (count);
}
