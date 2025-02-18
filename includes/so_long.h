/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:58 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 19:05:50 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 100
# define MAP_FRAME 6
# define COLLECTIBLE_FRAME 12
# define WALL_TEXTURE 0
# define FLOOR_TEXTURE 1
# define PLAYER_TEXTURE 2
# define EXIT_TEXTURE 3
# define EXIT_OPEN_TEXTURE 4

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	int		players;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*map_textures[MAP_FRAME];
	void	*collectible_textures[COLLECTIBLE_FRAME];
	int		collectible_frame;
	int		moves;
}			t_game;

// Prototypes
t_map		*parse_map(char *filename);
bool		check_map_validity(t_map *map);
int			key_hook(int keycode, t_game *game);
int			close_window(t_game *game);
bool		init_window(t_game *game);
bool		is_map_width_valid(t_map *map);
// void		render_map(t_game *game);
void		render_player(t_game *game);
void		render_tile(t_game *game);
bool		load_textures(t_game *game);
int			handle_keypress(int keycode, t_game *game);
bool		check_map_accessibility(t_map *map);
int			animate_collectibles(t_game *game);
void		update_position(t_game *game, int new_x, int new_y);

#endif
