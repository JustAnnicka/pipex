/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:48:26 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 12:56:42 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp = ft_gnl_calloc((BUFFER_SIZE + 2), sizeof(char));
	if (!temp)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read >= 0)
			temp[bytes_read] = '\0';
		if (bytes_read < 0)
		{
			if (buffer != NULL)
				free(buffer);
			return (free(temp), NULL);
		}
		buffer = ft_gnl_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*temp_string;
	size_t	i;

	i = 0;
	if (!buffer[i] || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp_string = ft_gnl_calloc((i + 2), sizeof(char));
	if (!temp_string)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp_string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp_string[i] = buffer[i];
		i++;
	}
	return (temp_string);
}

char	*ft_update_bufffer(char *buffer)
{
	char	*temp_string;
	int		start;
	int		i;

	start = 0;
	i = 0;
	while (buffer[start] != '\0' && buffer[start] != '\n')
		start++;
	if (!buffer[start])
		return (free(buffer), NULL);
	temp_string = ft_gnl_calloc((ft_gnl_strlen(buffer) - start + 1), sizeof(char));
	if (!temp_string)
		return (NULL);
	start++;
	while (buffer[start] && buffer[start] != '\0')
		temp_string[i++] = buffer[start++];
	free(buffer);
	return (temp_string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_update_bufffer(buffer);
	return (line);
}
