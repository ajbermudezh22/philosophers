/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:23:22 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/22 15:12:38 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*extract_line(char **storage)
{
	char	*line;
	char	*newline_pos;

	newline_pos = *storage;
	while (*newline_pos && *newline_pos != '\n')
		newline_pos++;
	if (*newline_pos == '\n')
		newline_pos++;
	line = ft_substr(*storage, 0, newline_pos - *storage);
	if (!line)
	{
		ft_free(storage);
		return (NULL);
	}
	newline_pos = ft_strdup(newline_pos);
	ft_free(storage);
	*storage = newline_pos;
	return (line);
}

static char	*add_buf_to_storage(char *storage, char *buffer, ssize_t bytes_read)
{
	char	*new_storage;

	buffer[bytes_read] = '\0';
	new_storage = ft_strjoin_free_s1(storage, buffer);
	if (!new_storage)
	{
		ft_free(&storage);
		return (NULL);
	}
	return (new_storage);
}

static char	*read_fd(int fd, char *storage, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(&buffer);
			ft_free(&storage);
			return (NULL);
		}
		storage = add_buf_to_storage(storage, buffer, bytes_read);
		if (!storage)
		{
			ft_free(&buffer);
			return (NULL);
		}
	}
	ft_free(&buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	if (!storage[fd])
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(storage[fd]);
		return (NULL);
	}
	storage[fd] = read_fd(fd, storage[fd], buffer);
	if (!storage[fd])
		return (NULL);
	if (!*storage[fd])
	{
		ft_free(&storage[fd]);
		return (NULL);
	}
	return (extract_line(&storage[fd]));
}
