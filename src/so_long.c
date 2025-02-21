/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:48:41 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/21 18:49:59 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "game.h"
#include "system.h"

t_game	*init_game_structure(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_with_game_error(NULL,
			"Failed to allocate memory for game structure", 0);
	game->map = map;
	game->moves = 0;
	return (game);
}

void	so_long_init(char *filename)
{
	t_game	*game;
	t_map	*map;

	map = parse_map(filename);
	check_map_validity(map);
	check_map_accessibility(map);
	game = init_game_structure(map);
	init_window(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_game(game);
}
