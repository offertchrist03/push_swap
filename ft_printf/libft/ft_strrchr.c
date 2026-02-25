/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:38:02 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/03 19:07:47 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				str_len;

	str = (unsigned char *)s;
	str_len = ft_strlen((const char *)str);
	if ((unsigned char)c == '\0')
		return ((char *)&str[str_len]);
	while (str_len > 0)
	{
		str_len--;
		if (str[str_len] == (unsigned char)c)
			return ((char *)&str[str_len]);
	}
	return (NULL);
}
