/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:28:57 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/03 13:00:22 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x] != '\0'
			&& game->map.grid[y][x] != '\n')
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int y, int x, t_flood_fill *ff)
{
	if (map[y][x] == '1' || map[y][x] == 'S')
		return ;
	if (map[y][x] == 'C')
		ff->collectibles_found++;
	if (map[y][x] == 'E')
	{
		ff->valid_exit = 1;
		map[y][x] = 'S';
		return ;
	}
	map[y][x] = 'S';
	flood_fill(map, y + 1, x, ff);
	flood_fill(map, y - 1, x, ff);
	flood_fill(map, y, x + 1, ff);
	flood_fill(map, y, x - 1, ff);
}

int	valid_path(t_game *game)
{
	t_flood_fill	ff;
	char			**copy;
	int				i;

	find_player(game);
	ff.collectibles = game->map.collectibles;
	ff.collectibles_found = 0;
	ff.valid_exit = 0;
	copy = copy_map(&game->map);
	if (!copy)
		error_exit(game, "Error\nMalloc error");
	flood_fill(copy, game->player.y, game->player.x, &ff);
	i = 0;
	while (i < game->map.height)
		free(copy[i++]);
	free(copy);
	if (ff.collectibles_found != ff.collectibles || ff.valid_exit != 1)
		return (1);
	return (0);
}
