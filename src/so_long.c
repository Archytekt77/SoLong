/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:48:41 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 01:28:26 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Initializes the game structure and allocates memory.
 */
static t_game	*init_game_structure(t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit_with_game_error(NULL,
			"Failed to allocate memory for game structure", 1);
	game->map = map;
	return (game);
}

/*
 * Initializes the game, including parsing and validating the map.
 */
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
