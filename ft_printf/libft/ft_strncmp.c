/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:31:19 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/03 18:49:19 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;
	size_t			i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	while (i < n && (buff_s1[i] || buff_s2[i]))
	{
		if (!(buff_s1[i] == buff_s2[i]))
			return (buff_s1[i] - buff_s2[i]);
		i++;
	}
	return (0);
}
