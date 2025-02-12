/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:32:49 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/12 19:18:33 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/Libft/libft.h"
#include "so_long.h"

bool	load_textures(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	game->textures[WALL_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->textures[FLOOR_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures[PLAYER_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->textures[COLLECTIBLE_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures[EXIT_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	while (i < 5)
	{
		if (!game->textures[i])
		{
			ft_printf("Error\nFailed to load texture %d\n", i);
			free_textures(game);
			return (false);
		}
		i++;
	}
	return (true);
}
