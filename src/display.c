/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:46 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/17 15:39:35 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->textures[0]);
	if (c == 'C')
		return (game->textures[3]);
	if (c == 'E')
		return (game->textures[4]);
	return (NULL);
}

/**
 * Affiche une tuile spécifique (sol, objets, joueur).
 */
void	render_tile(t_game *game, int x, int y)
{
	char	c;
	void	*img;

	mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x * 100, y
		* 100);
	c = game->map->map[y][x];
	img = get_tile_image(game, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * 100, y * 100);
	if (game->map->player_x == x && game->map->player_y == y)
		mlx_put_image_to_window(game->mlx, game->win, game->textures[2], x
			* 100, y * 100);
}

/**
 * Affiche toute la carte en une seule passe.
 */
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
