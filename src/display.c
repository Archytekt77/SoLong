/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:46 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 03:06:24 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"

// void	print_map(t_game *game)
// {
// 	int	i;

// 	printf("\n=== Carte après Flood Fill ===\n");
// 	i = 0;
// 	while (i < game->map->height)
// 	{
// 		printf("%s\n", game->map->map[i]);
// 		i++;
// 	}
// 	printf("==============================\n");
// }

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->textures[WALL_TEXTURE]);
	if (c == 'C')
	return (game->collectible_textures[game->collectible_frame]);
	if (c == 'E')
	{
		if (game->map->collectibles == 0)
			return (game->textures[EXIT_OPEN_TEXTURE]);
		return (game->textures[EXIT_TEXTURE]);
	}
	return (NULL);
}

/**
 * Affiche une tuile spécifique (sol, objets, joueur).
 */
void	render_tile(t_game *game, int x, int y)
{
	char	c;
	void	*img;

	mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x
		* TILE_SIZE, y * TILE_SIZE);
	c = game->map->map[y][x];
	img = get_tile_image(game, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (game->map->player_x == x && game->map->player_y == y)
		mlx_put_image_to_window(game->mlx, game->win, game->textures[2], x
			* TILE_SIZE, y * TILE_SIZE);
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
	// print_map(game);
}
