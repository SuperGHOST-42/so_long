/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:11 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/03 13:00:03 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (file[len - 1] != 'r'
		|| file[len - 2] != 'e'
		|| file[len - 3] != 'b'
		|| file[len - 4] != '.')
		return (1);
	return (0);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(NULL, "Error\nCould not open map file");
	count = 0;
	line = get_next_line_(fd);
	while ((line))
	{
		count++;
		free(line);
		line = get_next_line_(fd);
	}
	close(fd);
	return (count);
}

void	load_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	if (check_extension(file))
		error_exit(NULL, "Error\nFile must end with .ber");
	game->map.height = count_lines(file);
	if (game->map.height == 0)
		error_exit(NULL, "Error\nEmpty map");
	game->map.grid = malloc(sizeof(char *) * game->map.height);
	if (!game->map.grid)
		error_exit(game, "Error\nMalloc failed");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Error\nCould not open map file");
	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = get_next_line_(fd);
		if (!game->map.grid[i])
			error_exit(game, "Error\nFailed to assign map line");
		i++;
	}
	close(fd);
	game->map.width = ft_strlen_no_nl(game->map.grid[0]);
}
