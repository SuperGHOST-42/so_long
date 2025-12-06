/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:36 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/03 12:00:06 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player2(t_game *game, int *ptr_y, int *ptr_x)
{
	game->map.grid[game->player.y][game->player.x] = '0';
	game->player.y = *ptr_y;
	game->player.x = *ptr_x;
	game->map.grid[*ptr_y][*ptr_x] = 'P';
	render_map(game);
}

static void	move_player(t_game *game, int move_y, int move_x)
{
	int	new_y;
	int	new_x;

	new_y = game->player.y + move_y;
	new_x = game->player.x + move_x;
	if (new_y < 0 || new_y >= game->map.height)
		return ;
	if (new_x < 0 || new_x >= game->map.width)
		return ;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectibles--;
	if (game->map.grid[new_y][new_x] == 'E'
		&& game->map.collectibles != 0)
		return ;
	if (game->map.grid[new_y][new_x] == 'E'
		&& game->map.collectibles == 0)
	{
		ft_printf("YOU WON!\n");
		close_window(game);
	}
	move_player2(game, &new_y, &new_x);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == KEY_W)
	{
		ft_printf("move %i\n", game->count_moves);
		move_player(game, -1, 0);
	}
	if (key == KEY_S)
	{
		ft_printf("move %i\n", game->count_moves);
		move_player(game, 1, 0);
	}
	if (key == KEY_A)
	{
		ft_printf("move %i\n", game->count_moves);
		move_player(game, 0, -1);
	}
	if (key == KEY_D)
	{
		ft_printf("move %i\n", game->count_moves);
		move_player(game, 0, 1);
	}
	game->count_moves++;
	return (0);
}
