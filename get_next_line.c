/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikoubaz <yikoubaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:42:42 by yikoubaz          #+#    #+#             */
/*   Updated: 2025/11/12 13:17:04 by yikoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (stash)
				free(stash);
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_save_line(char *stash)
{
	char	*left_data;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	left_data = malloc(ft_strlen(stash) - i + 1);
	if (!left_data)
		return (NULL);
	j = 0;
	while (stash[i])
		left_data[j++] = stash[i++];
	left_data[j] = 0;
	free(stash);
	return (left_data);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash || !*stash)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(stash);
	stash = ft_save_line(stash);
	return (line);
}
