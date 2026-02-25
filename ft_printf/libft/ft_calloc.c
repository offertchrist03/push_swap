/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:15:20 by mahendri          #+#    #+#             */
/*   Updated: 2026/01/30 15:01:33 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*buffer;
	long long int	num;
	long long int	s;

	num = (long int)number;
	s = (long int)size;
	if ((s < 0 && num == 0) || (s == 0 && num < 0))
		return (malloc(0));
	if ((s < 0 || num < 0))
		return (NULL);
	buffer = (unsigned char *)malloc((num * s) * sizeof(unsigned char));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, num * s);
	return ((void *)buffer);
}
