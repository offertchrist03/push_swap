/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:42:00 by mahendri          #+#    #+#             */
/*   Updated: 2026/01/24 12:56:28 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *str, char sep)
{
	size_t	count;
	size_t	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (count);
}

static size_t	word_len(char const *str, char sep)
{
	size_t	i;

	if (!str)
		return (0);
	if (sep == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static char	**free_split(char **split, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**do_split(char **split, size_t split_len, char const *s, char c)
{
	size_t	split_i;
	size_t	temp_word_len;
	size_t	i;

	split_i = 0;
	i = 0;
	while (split_i < split_len)
	{
		while (s[i] && s[i] == c)
			i++;
		temp_word_len = word_len(&s[i], c);
		split[split_i] = ft_substr(s, i, temp_word_len);
		if (!split[split_i])
			return (free_split(split, split_i));
		i += temp_word_len;
		split_i++;
	}
	split[split_i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_len;

	if (!s)
		return (NULL);
	split_len = word_count(s, c);
	split = (char **)malloc((split_len + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = do_split(split, split_len, s, c);
	return (split);
}
