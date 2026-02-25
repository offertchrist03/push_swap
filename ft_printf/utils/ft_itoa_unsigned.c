/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 08:33:47 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/10 11:03:23 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_number_len(unsigned int n)
{
	size_t		count;
	long int	num;

	num = n;
	count = 0;
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	count++;
	return (count);
}

static void	do_itoa(char *buff_number, unsigned long num, size_t i)
{
	if (num > 9)
	{
		do_itoa(buff_number, (num / 10), i - 1);
		num = num % 10;
	}
	buff_number[i] = num + '0';
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*buff_number;
	size_t			buff_len;
	unsigned long	num;

	num = n;
	buff_len = ft_number_len(n);
	buff_number = (char *)malloc((buff_len + 1) * sizeof(char));
	if (!buff_number)
		return (NULL);
	do_itoa(buff_number, (unsigned long)num, buff_len - 1);
	buff_number[buff_len] = '\0';
	return (buff_number);
}
