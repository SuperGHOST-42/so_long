/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:50:17 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/03 13:01:16 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_window(t_game *game)
{
	int	w;
	int	h;

	w = game->map.width * TILE;
	h = game->map.height * TILE;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "Error\nInitializing MLX");
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		error_exit(game, "Error\nCreating window");
}

int	close_window(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}
