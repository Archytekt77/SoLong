/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:48:41 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/19 22:06:12 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "game.h"
#include "system.h"

t_game	*game_init(t_game *game)
{
	int	i;

	i = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	while (i < TEXTURES_TAB)
	{
		game->textures[i] = NULL;
		i++;
	}
	game->moves = 0;
	return (game);
}

void	so_long_init(char *filename)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_with_game_error(NULL, "Memory allocation failed", 0);
	game_init(game);
	game->map = parse_map(filename);
	if (!game->map || !check_map_validity(game->map)
		|| !check_map_accessibility(game->map))
	{
		printf("Here 4\n");
		free(game);
		exit_with_game_error(NULL, "Invalid map", 0);
	}
	// exit_with_game_error(game, "Invalid map", 0);
	if (!init_window(game))
		exit_with_game_error(game, "Failed to initialize game", 0);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_game(game);
}
