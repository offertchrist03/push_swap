/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainrakot <ainrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:38:07 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/24 15:51:59 by ainrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	buffer = (unsigned char *)s;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

char	*copy_str(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (NULL);
	if (!dest)
		return (ft_calloc((1), sizeof(char)));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*cat_stash_buff(char *stash, char *buffer)
{
	char	*new_stash;
	size_t	new_stash_len;

	if (!stash)
		return (NULL);
	new_stash_len = ft_strlen(stash) + ft_strlen(buffer);
	new_stash = (char *)ft_calloc((new_stash_len + 1), sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	new_stash = copy_str(new_stash, stash, ft_strlen(stash));
	new_stash = copy_str(new_stash, buffer, ft_strlen(buffer));
	free(stash);
	return (new_stash);
}
