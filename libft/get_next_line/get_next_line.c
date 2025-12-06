/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:17:21 by arpereir          #+#    #+#             */
/*   Updated: 2025/06/11 13:37:37 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = clean_stash(stash);
	return (line);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*clean_stash(char *stash)
{
	size_t	i;
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_strdup(stash + i + 1);
	free(stash);
	return (rest);
}
/*
 int	main(int argc, char **argv)
{
	char	*line;
	int		fd, fd2;		
	static int	i;
	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
		printf("fd less than 0:(\n");	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", ++i, line);
		free(line);
	}
	close(fd);
	return (0);
}*/
