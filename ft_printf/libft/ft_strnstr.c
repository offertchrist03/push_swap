/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:41 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/03 18:54:51 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_little(const char *big, const char *little, size_t len,
		unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < ft_strlen(little))
	{
		if (big[i + j] == little[j] && (i + j) < len)
			j++;
		else
			break ;
	}
	if (j == ft_strlen(little))
		return ((char *)&big[i]);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			res = find_little(big, little, len, i);
			if (res)
				return (res);
		}
		i++;
	}
	return (NULL);
}
