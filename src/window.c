/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:13 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/26 13:59:16 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "game.h"
#include "system.h"

/*
 * Handles keyboard input for player movement and game exit.
 */
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
	load_textures(game);
	render_map(game);
	return (true);
}
