#include "../includes/Libft/libft.h"
#include "../includes/so_long_bonus.h"

void	update_position(t_game *game, int new_x, int new_y)
{
	char	current_cell;

	current_cell = game->map->map[new_y][new_x];
	if (current_cell == 'C')
		game->map->collectibles--;
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

/**
 * Vérifie si le joueur peut se déplacer à la position donnée.
 */
bool	can_move_to(t_game *game, int x, int y)
{
	char	cell;

	cell = game->map->map[y][x];
	if (cell == '1')
		return (false);
	if (cell == 'E' && game->map->collectibles > 0)
	{
		ft_printf("You must collect all items before exiting!\n");
		return (false);
	}
	if (cell == 'E' && game->map->collectibles == 0)
	{
		ft_printf("You won in %d moves!\n", game->moves + 1);
		close_window(game);
	}
	return (true);
}

/**
 * Initialise un déplacement fluide vers la direction souhaitée.
 */
void	start_movement(t_game *game, int dx, int dy)
{
	if (game->moving)
		return ;
	game->target_x = game->player_x + dx;
	game->target_y = game->player_y + dy;
	game->moving = 1;
	if (dx > 0)
		game->last_direction = DIR_RIGHT;
	else if (dx < 0)
		game->last_direction = DIR_LEFT;
	else if (dy > 0)
		game->last_direction = DIR_DOWN;
	else if (dy < 0)
		game->last_direction = DIR_UP;
}

/**
 * Gère le déplacement fluide du joueur.
 */
int	update_movement(void *param)
{
	t_game	*game;
	float	speed;

	game = (t_game *)param;
	if (!game->moving)
		return (0);
	speed = 0.1;
	if (game->player_x < game->target_x)
		game->player_x += speed;
	if (game->player_x > game->target_x)
		game->player_x -= speed;
	if (game->player_y < game->target_y)
		game->player_y += speed;
	if (game->player_y > game->target_y)
		game->player_y -= speed;
	if (fabs(game->player_x - game->target_x) < speed && fabs(game->player_y
			- game->target_y) < speed)
	{
		game->player_x = game->target_x;
		game->player_y = game->target_y;
		game->moving = 0;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	return (0);
}

/**
 * Gère les entrées clavier du joueur pour initier un mouvement.
 */
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 'w' || keycode == 65362)
		start_movement(game, 0, -1);
	else if (keycode == 's' || keycode == 65364)
		start_movement(game, 0, 1);
	else if (keycode == 'a' || keycode == 65361)
		start_movement(game, -1, 0);
	else if (keycode == 'd' || keycode == 65363)
		start_movement(game, 1, 0);
	return (0);
}
