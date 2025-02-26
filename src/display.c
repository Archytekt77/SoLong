/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:46 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/26 13:58:27 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "game.h"

/*
 * Renders the player on the window.
 */
void	render_player(t_game *game)
{
	void	*img;

	img = game->textures[PLAYER_TEXTURE];
	if (!img)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, game->map->player_x
		* TILE_SIZE, game->map->player_y * TILE_SIZE);
}

/*
 * Retrieves the appropriate texture for a given tile character.
 */
static void	*get_tile_image(t_game *game, char c)
{
	static const char	tiles[] = {'0', '1', 'P', 'C', 'E'};
	static const int	textures[] = {FLOOR_TEXTURE, WALL_TEXTURE,
		PLAYER_TEXTURE, COLLECTIBLE_TEXTURE, EXIT_TEXTURE};
	int					i;

	i = 0;
	while (i < TEXTURES_TAB)
	{
		if (c == tiles[i])
			return (game->textures[textures[i]]);
		i++;
	}
	ft_printf("Warning: Unknown tile '%c' found in map\n", c);
	return (NULL);
}

/*
 * Renders the entire game map.
 */
void	render_map(t_game *game)
{
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			img = get_tile_image(game, game->map->map[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
