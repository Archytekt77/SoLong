/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:37 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 03:24:35 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx-linux/mlx.h"
#include "error_handling.h"
#include "so_long.h"

int animate_collectibles(t_game *game)
{
    game->collectible_frame++;
    if (game->collectible_frame >= COLLECTIBLE_FRAME)
        game->collectible_frame = 0;
    render_map(game);
    return (0);
}

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
	game.moves = 0;
	if (!init_window(&game))
		exit_with_game_error(&game, "Failed to initialize game", 0);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	mlx_loop_hook(game.mlx, animate_collectibles, &game);
	free_game(&game);
	return (0);
}
