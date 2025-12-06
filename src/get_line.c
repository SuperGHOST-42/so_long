/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:39:02 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:28:46 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_next_line_(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		r;

	i = 0;
	line = malloc(10000);
	if (!line)
		return (NULL);
	while (1)
	{
		r = read(fd, &c, 1);
		if (r <= 0)
			break ;
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	if (i == 0 && r <= 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}
