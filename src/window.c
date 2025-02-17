/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:13 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/17 14:41:27 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/minilibx-linux/mlx.h"
#include "../includes/so_long_bonus.h"
#include "error_handling.h"

bool	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_game_error(game, "Failed to initialize mlx", 0);
	if (game->map->width <= 0 || game->map->height <= 0)
		exit_with_game_error(game, "Invalid map dimensions", 0);
	game->win = mlx_new_window(game->mlx, game->map->width * 100,
			game->map->height * 100, "so_long");
	if (!game->win)
		exit_with_game_error(game, "Failed to create window", 0);
	if (!load_textures(game))
		exit_with_game_error(game, "Failed to load textures", 0);
	render_map(game);
	return (true);
}

int	close_window(t_game *game)
{
	free_game(game);
	ft_printf("Game closed.\n");
	exit(0);
}
