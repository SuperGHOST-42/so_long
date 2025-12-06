/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:16 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/03 12:59:22 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map(t_game *game)
{
	t_map	*m;

	m = &game->map;
	if (check_rectangular(m))
		error_exit(game, "Error\nMap is not rectangular");
	if (check_chars(m))
		error_exit(game, "Error\nInvalid character in map");
	if (count_elements(m))
		error_exit(game, "Error\nInvalid number of elements");
	if (check_walls(m))
		error_exit(game, "Error\nMap is not surrounded by walls");
	if (valid_path(game))
		error_exit(game, "Error\nInvalid path");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.count_moves = 1;
	if (argc != 2)
		error_exit(&game, "Error\nUse: ./so_long map.ber");
	load_map(&game, argv[1]);
	validate_map(&game);
	open_window(&game);
	load_sprites(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
