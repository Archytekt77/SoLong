/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:54:30 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/17 18:53:17 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/error_handling.h"
#include "../includes/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <limits.h>
#include <unistd.h>

/**
 * Charge les textures de l'animation idle du joueur.
 */
bool	load_animation_player_idle(t_game *game)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	game->player_idle[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/idle_00.xpm", &width, &height);
	game->player_idle[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/idle_01.xpm", &width, &height);
	game->player_idle[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/idle_02.xpm", &width, &height);
	game->player_idle[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/idle_03.xpm", &width, &height);
	while (i < 4)
	{
		if (!game->player_idle[i])
		{
			printf("🔍 Chargement de : %p\n", game->player_idle[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * Charge toutes les textures du jeu, y compris les animations du joueur.
 */
bool	load_textures(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	printf("🔍 Chargement de : %s\n", "textures/wall.xpm");
	game->textures[WALL_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	game->textures[FLOOR_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &width, &height);
	game->textures[COLLECTIBLE_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &width, &height);
	game->textures[EXIT_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &width, &height);
	while (i < 4)
	{
		if (!game->textures[i])
			exit_with_game_error(game, "Failed to load texture", 0);
		i++;
	}
	if (!load_animation_player_idle(game))
		exit_with_game_error(game, "Failed to load Idle animation", 0);
	return (true);
}
