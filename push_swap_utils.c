/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:12:51 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/16 15:45:18 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(void *s1, void *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen((const char *)s1);
	len2 = ft_strlen((const char *)s2);
	len = len1;
	if (len2 > len)
		len = len2;
	return (ft_memcmp(s1, s2, len));
}

int	compare_numbers(void *s1, void *s2)
{
	char	*n1;
	char	*n2;
	int		sign;

	sign = 1;
	if (!s1 && !s2)
		return (0);
	n1 = (char *)s1;
	n2 = (char *)s2;
	if ((n1[0] == '-') && !(n2[0] == '-'))
		return (-1);
	if (!(n1[0] == '-') && (n2[0] == '-'))
		return (1);
	if ((n1[0] == '-') && (n2[0] == '-'))
		sign = -1;
	if ((n1[0] == '-') || (n1[0] == '+'))
		n1 = &n1[1];
	if ((n2[0] == '-') || (n2[0] == '+'))
		n2 = &n2[1];
	if (ft_strlen(n1) > ft_strlen(n2))
		return (sign * 1);
	if (ft_strlen(n1) < ft_strlen(n2))
		return (sign * -1);
	return (sign * ft_memcmp(n1, n2, ft_strlen(n1)));
}

long int	long_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_num(char *str)
{
	int			i;
	long int	num;

	if (!*str)
		return (0);
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) > 1)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = long_atoi((const char *)str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
