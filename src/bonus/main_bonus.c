#include "../includes/minilibx-linux/mlx.h"
#include "../includes/so_long_bonus.h"
#include "error_handling.h"

bool	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Failed to open file");
		return (false);
	}
	close(fd);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !strstr(argv[1], ".ber"))
		exit_with_game_error(NULL, "Invalid map file. Please use a .ber file.",
			0);
	if (!file_exists(argv[1]))
		return (1);
	game.map = parse_map(argv[1]);
	if (!game.map)
		exit_with_game_error(&game, "Failed to parse map", 0);
	if (!check_map_validity(game.map))
		exit_with_game_error(&game, "Invalid map", 0);
	if (!check_map_accessibility(game.map))
		exit_with_game_error(&game, "Map is not playable", 0);
	if (!init_window(&game))
		exit_with_game_error(&game, "Failed to initialize game", 0);
	game.moves = 0;
	game.moving = 0;
	game.current_frame_idle = 0;
	game.current_frame_run = 0;
	game.current_frame_death = 0;
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, animate_player, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
