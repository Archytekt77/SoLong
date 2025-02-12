#include "../includes/Libft/libft.h"
#include "so_long.h"

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

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x + dx;
	new_y = game->map->player_y + dy;
	if (can_move_to(game, new_x, new_y))
		update_position(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 'w' || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
