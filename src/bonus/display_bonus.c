#include "../includes/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->textures[0]);
	if (c == 'C')
		return (game->textures[3]);
	if (c == 'E')
		return (game->textures[4]);
	return (NULL);
}

/**
 * Retourne l'image du joueur en fonction de son état et de la direction.
 */
void	*get_player_sprite(t_game *game)
{
	if (game->moving)
		return (game->player_run[game->current_frame_run]);
	return (game->player_idle[game->current_frame_idle]);
}

/**
 * Affiche une tuile spécifique (sol, objets, joueur avec animation).
 */
void	render_tile(t_game *game, int x, int y)
{
	char	c;
	void	*img;

	mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x
		* TILE_SIZE, y * TILE_SIZE);
	c = game->map->map[y][x];
	img = get_tile_image(game, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
			* TILE_SIZE);
	if ((int)game->player_x == x && (int)game->player_y == y)
		mlx_put_image_to_window(game->mlx, game->win, get_player_sprite(game), x
			* TILE_SIZE, y * TILE_SIZE);
}

/**
 * Affiche toute la carte.
 */
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

/**
 * Gère l'animation du joueur en changeant les frames.
 */
int	animate_player(void *param)
{
	t_game		*game;
	static int	frame_counter = 0;

	game = (t_game *)param;
	frame_counter++;
	if (frame_counter > 10)
	{
		game->current_frame_idle = (game->current_frame_idle + 1) % 4;
		game->current_frame_run = (game->current_frame_run + 1) % 6;
		frame_counter = 0;
	}
	return (0);
}
