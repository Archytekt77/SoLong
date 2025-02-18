/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:32:49 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/18 03:14:55 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "error_handling.h"
#include "so_long.h"

bool	load_textures(t_game *game)
{
	int	i;
	int	width;
	int	height;
	char path[50];

	i = 0;
	game->textures[WALL_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->textures[FLOOR_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures[PLAYER_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/idle/idle_00.xpm", &width, &height);
	game->textures[COLLECTIBLE_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible/collectible_00.xpm", &width, &height);
	game->textures[EXIT_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_00.xpm", &width, &height);
	game->textures[EXIT_OPEN_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_01.xpm", &width, &height);
	while (i < 6)
	{
		if (!game->textures[i])
			exit_with_game_error(game, "Failed to load texture", 0);
		i++;
	}
	for (i = 0; i < COLLECTIBLE_FRAME; i++)
    {
        sprintf(path, "textures/collectible/collectible_%02d.xpm", i);
		printf("Loading collectible texture: %s\n", path);
        game->collectible_textures[i] = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
        if (!game->collectible_textures[i])
            exit_with_game_error(game, "Failed to load collectible texture", 0);
    }
    game->collectible_frame = 0;
	return (true);
}
