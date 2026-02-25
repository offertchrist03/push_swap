/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 08:33:47 by mahendri          #+#    #+#             */
/*   Updated: 2026/01/26 15:45:54 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_len(int n)
{
	size_t		count;
	long int	num;

	num = n;
	if (num < 0)
		num *= -1;
	count = 0;
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	count++;
	return (count);
}

static void	do_itoa(char *buff_number, long int num, size_t i)
{
	if (num > 9)
	{
		do_itoa(buff_number, (num / 10), i - 1);
		num = num % 10;
	}
	buff_number[i] = num + '0';
}

char	*ft_itoa(int n)
{
	char		*buff_number;
	size_t		buff_len;
	long int	num;

	num = n;
	buff_len = ft_number_len(n);
	if (num < 0)
		buff_len += 1;
	buff_number = (char *)malloc((buff_len + 1) * sizeof(char));
	if (!buff_number)
		return (NULL);
	if (num < 0)
	{
		buff_number[0] = '-';
		num *= -1;
	}
	do_itoa(buff_number, num, buff_len - 1);
	buff_number[buff_len] = '\0';
	return (buff_number);
}
