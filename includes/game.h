/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:58 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 02:13:02 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "textures.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h> // for debugging
# include <stdlib.h>
# include <string.h>

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
	void	*textures[TEXTURES_TAB];
	int		moves;
}			t_game;

# ifndef KEYS_H
#  define KEYS_H

#  define KEY_ESC 65307
#  define KEY_W 'w'
#  define KEY_A 'a'
#  define KEY_S 's'
#  define KEY_D 'd'
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363

# endif

void		so_long_init(char *filename);
t_map		*parse_map(char *filename);
void		is_map_width_valid(t_map *map);
void		check_map_validity(t_map *map);
void		check_map_accessibility(t_map *map);
void		init_window(t_game *game);
int			close_window(t_game *game);
bool		load_textures(t_game *game);
void		render_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		render_player(t_game *game);

#endif
