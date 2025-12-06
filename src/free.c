/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:25:03 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/04 23:07:18 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_sprite(t_game *game)
{
	if (game->sprite.wall)
		mlx_destroy_image(game->mlx, game->sprite.wall);
	if (game->sprite.floor)
		mlx_destroy_image(game->mlx, game->sprite.floor);
	if (game->sprite.player)
		mlx_destroy_image(game->mlx, game->sprite.player);
	if (game->sprite.collect)
		mlx_destroy_image(game->mlx, game->sprite.collect);
	if (game->sprite.exit)
		mlx_destroy_image(game->mlx, game->sprite.exit);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_all(t_game *game)
{
	free_map(&game->map);
	if (game->mlx)
		free_sprite(game);
/* 	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
		mlx_destroy_display(game->mlx); */
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
}
