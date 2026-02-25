/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_split_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:52:40 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/23 11:21:50 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin_with_space(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	str_len1;
	size_t	str_len2;

	if (!s1 || !s2)
		return (NULL);
	str_len1 = ft_strlen(s1);
	str_len2 = ft_strlen(s2);
	buffer = ft_calloc((str_len1 + str_len2 + 2), sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	ft_strlcat(buffer, s1, str_len1 + str_len2 + 2);
	ft_strlcat(buffer, " ", str_len1 + str_len2 + 2);
	ft_strlcat(buffer, s2, str_len1 + str_len2 + 2);
	return (buffer);
}

size_t	split_len(char **split)
{
	size_t	i;

	if (!split || !*split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	**free_split(char **split, size_t size)
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

int	skip_flag_on_check(char *arg, int *has_number)
{
	int	i;

	i = 0;
	if (arg[i] == '-' && arg[i + 1] == '-')
	{
		*has_number = 1;
		i += 2;
		while (ft_isalpha(arg[i]))
			i++;
	}
	return (i);
}
