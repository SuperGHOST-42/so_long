/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:04 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:35:38 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image(t_game *game, void *img, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

static void	draw_tile(t_game *game, char c, int y, int x)
{
	put_image(game, game->sprite.floor, y, x);
	if (c == '1')
		put_image(game, game->sprite.wall, y, x);
	else if (c == 'P')
		put_image(game, game->sprite.player, y, x);
	else if (c == 'C')
		put_image(game, game->sprite.collect, y, x);
	else if (c == 'E')
		put_image(game, game->sprite.exit, y, x);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, game->map.grid[y][x], y, x);
			x++;
		}
		y++;
	}
}
