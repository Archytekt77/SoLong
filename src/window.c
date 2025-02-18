/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:13 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/18 19:16:20 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/minilibx-linux/mlx.h"
#include "error_handling.h"
#include "so_long.h"

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
	render_background(game);
	render_player(game);
	mlx_loop_hook(game->mlx, animate_collectibles, game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (true);
}

int	close_window(t_game *game)
{
	free_game(game);
	ft_printf("Game closed.\n");
	exit(0);
}
