/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:46 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/12 01:50:54 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->img_wall);
	if (c == 'C')
		return (game->img_collectible);
	if (c == 'E')
		return (game->img_exit);
	return (NULL);
}

/**
 * Affiche uniquement le sol sur toute la carte.
 */
void	render_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
				* 128, y * 128);
			x++;
		}
		y++;
	}
}

/**
 * Affiche les éléments statiques de la carte (murs, collectibles, sortie).
 */
void	render_objects(t_game *game)
{
	int		x;
	int		y;
	char	c;
	void	*img;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			c = game->map->map[y][x];
			img = get_tile_image(game, c);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x * 128, y
					* 128);
			x++;
		}
		y++;
	}
}

/**
 * Affiche le joueur par-dessus tout.
 */
void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->map->player_x * 128, game->map->player_y * 128);
}

/**
 * Fonction principale d'affichage : affiche tout dans le bon ordre.
 */
void	render_map(t_game *game)
{
	render_floor(game);
	render_objects(game);
	render_player(game);
}
