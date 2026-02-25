/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:03:59 by mahendri          #+#    #+#             */
/*   Updated: 2026/01/30 09:57:48 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	str_len1;
	size_t	str_len2;

	if (!s1 || !s2)
		return (NULL);
	str_len1 = ft_strlen(s1);
	str_len2 = ft_strlen(s2);
	buffer = malloc((str_len1 + str_len2 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	ft_strlcat(buffer, s1, str_len1 + str_len2 + 1);
	ft_strlcat(buffer, s2, str_len1 + str_len2 + 1);
	return (buffer);
}
