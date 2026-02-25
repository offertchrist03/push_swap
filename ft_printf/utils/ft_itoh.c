/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:45:57 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/12 12:55:03 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	hex_length(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

static void	do_itoh(char *hex, unsigned long num, int hex_i)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
		do_itoh(hex, num / 16, hex_i - 1);
	hex[hex_i] = base[num % 16];
}

char	*ft_itoh(unsigned long num)
{
	char	*hex;
	int		hex_len;

	hex_len = hex_length(num);
	hex = (char *)malloc((hex_len + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	hex[hex_len] = '\0';
	do_itoh(hex, num, hex_len - 1);
	return (hex);
}
