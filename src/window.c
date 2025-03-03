/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:13 by archytekt         #+#    #+#             */
/*   Updated: 2025/03/03 01:37:40 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Handles keyboard input for player movement and game exit.
 */
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

/*
 * This function closes the window and frees the game structure
 */
int	close_window(t_game *game)
{
	free_game(game);
	ft_printf("Game closed.\n");
	exit(EXIT_SUCCESS);
}

/*
 * Initializes the game window using MiniLibX.
 */
void	init_window(t_game *game)
{
	if (!game || !game->map)
		exit_with_game_error(game, "Game structure isn't initialized.", 0);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_game_error(game, "Failed to initialize mlx", 1);
	load_textures(game);
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_with_game_error(game, "Failed to create window", 1);
	render_map(game);
}
