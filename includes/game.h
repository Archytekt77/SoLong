/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:58 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/24 13:42:47 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "textures.h"
# include <fcntl.h>
# include <stdbool.h>
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

void		so_long_init(char *filename);
t_map		*parse_map(char *filename);
bool		is_map_width_valid(t_map *map);
bool		check_map_validity(t_map *map);
bool		check_map_accessibility(t_map *map);
bool		init_window(t_game *game);
int			close_window(t_game *game);
bool		load_textures(t_game *game);
void		render_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		render_player(t_game *game);

#endif
