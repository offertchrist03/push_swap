/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:30 by mahendri          #+#    #+#             */
/*   Updated: 2026/01/26 13:06:01 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	index_start(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i] && in_set(str[i], set))
		i++;
	return (i);
}

static size_t	index_end(char const *str, char const *set)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	len--;
	while (len > 0 && in_set(str[len], set))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = index_start(s1, set);
	end = index_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	trimed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trimed)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		trimed[i] = s1[start];
		i++;
		start++;
	}
	trimed[i] = '\0';
	return (trimed);
}
