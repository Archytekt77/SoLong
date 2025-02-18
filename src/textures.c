/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:32:49 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/18 18:22:31 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "error_handling.h"
#include "so_long.h"

bool	load_textures(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	path[50];

	i = 0;
	game->map_textures[WALL_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->map_textures[FLOOR_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->map_textures[PLAYER_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/idle/idle_00.xpm", &width, &height);
	game->map_textures[EXIT_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_00.xpm", &width, &height);
	game->map_textures[EXIT_OPEN_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_01.xpm", &width, &height);
	while (i < 5)
	{
		if (!game->map_textures[i])
			exit_with_game_error(game, "Failed to load texture 2", 0);
		i++;
	}
	i = 0;
	while (i < COLLECTIBLE_FRAME)
	{
		snprintf(path, sizeof(path),
			"textures/collectible/collectible_%02d.xpm", i);
		game->collectible_textures[i] = mlx_xpm_file_to_image(game->mlx, path,
				&width, &height);
		if (!game->collectible_textures[i])
			exit_with_game_error(game, "Failed to load collectible texture", 0);
		i++;
	}
	game->collectible_frame = 0;
	return (true);
}
