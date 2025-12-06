/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:00:00 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/04 23:05:13 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE 128
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	char	**grid;
	int		width;	//largura
	int		height;	//altura
	int		collectibles;
	int		exits;
	int		players;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		collected;
}	t_player;

typedef struct s_flood_fill
{
	int		collectibles;
	int		collectibles_found;
	int		valid_exit;
}	t_flood_fill;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_sprites;

typedef struct s_game
{
	long		count_moves;
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_sprites	sprite;
}	t_game;

/* utils */
void	error_exit(t_game *game, char *msg);
void	free_map(t_map *map);
void	free_sprite(t_game *game);
void	free_all(t_game *game);

/* map parsing */
void	load_map(t_game *game, char *file);
int		ft_strlen_no_nl(char *s);
char	*get_next_line_(int fd);

/* validate map */
int		check_rectangular(t_map *map);
int		check_chars(t_map *map);
int		count_elements(t_map *map);
int		check_walls(t_map *map);

/* flood fill */
int		valid_path(t_game *game);

/* window */
void	open_window(t_game *game);
int		close_window(t_game *game);

/* sprites */
void	load_sprites(t_game *game);

/* render */
void	render_map(t_game *game);

/* events */
int		key_press(int key, t_game *game);

#endif
