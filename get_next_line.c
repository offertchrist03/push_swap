/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:43 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/11 05:04:01 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	end_read(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_stash(int fd, char *remains, char *buffer)
{
	char	*stash;
	ssize_t	read_bytes;

	stash = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!stash)
		return (NULL);
	if (remains && remains[0])
		stash = cat_stash_buff(stash, remains);
	ft_bzero(remains, (BUFFER_SIZE + 1));
	read_bytes = 1;
	while (read_bytes > 0 && !end_read(stash))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		stash = cat_stash_buff(stash, buffer);
	}
	return (stash);
}

static int	fetch_rest(char	*remains, char *stash, size_t start)
{
	size_t	i;

	if (!stash[start])
	{
		free(stash);
		return (0);
	}
	i = 0;
	while (stash[start + i] && i < (BUFFER_SIZE + 1))
	{
		remains[i] = stash[start + i];
		i++;
	}
	remains[i] = '\0';
	free(stash);
	return (1);
}

static char	*slice_paragraph(char *stash)
{
	size_t	i;
	char	*paragraph;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	paragraph = ft_calloc((i + 1), sizeof(char));
	if (!paragraph)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		paragraph[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		paragraph[i] = '\n';
	return (paragraph);
}

char	*get_next_line(int fd)
{
	static char	remains[BUFFER_SIZE + 1];
	char		*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	stash = read_stash(fd, remains, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = slice_paragraph(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	if (!fetch_rest(remains, stash, ft_strlen(line)))
		ft_bzero(remains, (BUFFER_SIZE + 1));
	return (line);
}
