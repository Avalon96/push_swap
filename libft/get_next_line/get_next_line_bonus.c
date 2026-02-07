/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:51:57 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/07 12:17:41 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char *stash)
{
	char	*line;
	int		len;

	if (!stash || !*stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strncpy_void(line, stash, len + 1);
	return (line);
}

static char	*save_remainder(char *stash)
{
	char	*new_stash;
	size_t	start;
	size_t	len;

	if (!stash)
		return (NULL);
	start = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	if (stash[start] == '\n')
		start++;
	if (!stash[start])
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen(stash + start);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	ft_strncpy_void(new_stash, stash + start, len + 1);
	free(stash);
	return (new_stash);
}

static int	read_to_stash(int fd, char **stash, char *buffer)
{
	int	bytes_read;

	bytes_read = 0;
	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*stash = ft_strjoin_free(*stash, buffer);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read_to_stash(fd, &stash[fd], buffer) < 0)
	{
		free(buffer);
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	stash[fd] = save_remainder(stash[fd]);
	free(buffer);
	return (line);
}
