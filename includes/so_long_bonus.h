#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <../includes/minilibx-linux/mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 100

typedef enum e_direction
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN
}				t_direction;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			exits;
	int			players;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		*textures[4];
	// Animations
	void		*player_idle[4];

	int			current_frame_idle;
	t_direction	last_direction;

	int			moves;
}				t_game;

# define WALL_TEXTURE 0
# define FLOOR_TEXTURE 1
# define COLLECTIBLE_TEXTURE 2
# define EXIT_TEXTURE 3

// Prototypes
t_map			*parse_map(char *filename);
bool			check_map_validity(t_map *map);
int				key_hook(int keycode, t_game *game);
int				close_window(t_game *game);
bool			init_window(t_game *game);
bool			is_map_width_valid(t_map *map);
void			render_map(t_game *game);
bool			load_textures(t_game *game);
int				handle_keypress(int keycode, t_game *game);
bool			check_map_accessibility(t_map *map);
void			start_movement(t_game *game, int dx, int dy);
int				animate_player(void *param);
void			move_player(t_game *game, int dx, int dy);

#endif