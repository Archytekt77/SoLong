/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:58 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 03:00:15 by archytekt        ###   ########.fr       */
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
# define WALL_TEXTURE 0
# define FLOOR_TEXTURE 1
# define PLAYER_TEXTURE 2
# define COLLECTIBLE_TEXTURE 3
# define EXIT_TEXTURE 4
# define EXIT_OPEN_TEXTURE 5
# define COLLECTIBLE_FRAME 12

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
	void	*textures[6];
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
void		render_map(t_game *game);
bool		load_textures(t_game *game);
int			handle_keypress(int keycode, t_game *game);
bool		check_map_accessibility(t_map *map);

#endif
