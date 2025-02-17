#include "../includes/minilibx-linux/mlx.h"
#include "../includes/Libft/libft.h"
#include "../includes/so_long_bonus.h"
#include "error_handling.h"

bool	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_game_error(game, "Failed to initialize mlx", 0);
	if (game->map->width <= 0 || game->map->height <= 0)
		exit_with_game_error(game, "Invalid map dimensions", 0);
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_with_game_error(game, "Failed to create window", 0);
	if (!load_textures(game))
		exit_with_game_error(game, "Failed to load textures", 0);
	render_map(game);
	// Ajouter un hook pour l'animation et le mouvement
	mlx_loop_hook(game->mlx, update_movement, game);
	return (true);
}

int	close_window(t_game *game)
{
	free_game(game);
	ft_printf("Game closed.\n");
	exit(0);
}
