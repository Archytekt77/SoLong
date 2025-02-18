/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:46 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 19:01:06 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"

// /**
//  * Retourne l'image correspondant à un élément de la carte.
//  */
// void	*get_tile_image(t_game *game, char c)
// {
// 	if (!game || !game->map_textures || !game->collectible_textures)
// 		return (NULL);
// 	if (c == '1')
// 		return (game->map_textures[WALL_TEXTURE]);
// 	if (c == 'C')
// 	{
// 		if (game->collectible_frame >= COLLECTIBLE_FRAME)
// 			return (NULL);
// 		return (game->collectible_textures[game->collectible_frame]);
// 	}
// 	if (c == 'E')
// 	{
// 		if (game->map->collectibles == 0)
// 			return (game->map_textures[EXIT_OPEN_TEXTURE]);
// 		return (game->map_textures[EXIT_TEXTURE]);
// 	}
// 	return (NULL);
// }

// /**
//  * Affiche une tuile spécifique (sol, objets, joueur).
//  */
// void	render_tile(t_game *game, int x, int y)
// {
// 	char	c;
// 	void	*img;

// 	mlx_put_image_to_window(game->mlx, game->win,
// 		game->map_textures[FLOOR_TEXTURE], x * TILE_SIZE, y * TILE_SIZE);
// 	c = game->map->map[y][x];
// 	img = get_tile_image(game, c);
// 	if (img)
// 		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
// 			* TILE_SIZE);
// 	if (game->map->player_x == x && game->map->player_y == y)
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->map_textures[PLAYER_TEXTURE], x * TILE_SIZE, y * TILE_SIZE);
// }

// /**
//  * Affiche toute la carte en une seule passe.
//  */
// void	render_map(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < game->map->height)
// 	{
// 		x = 0;
// 		while (x < game->map->width)
// 		{
// 			render_tile(game, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (!game || !game->map_textures || !game->collectible_textures)
		return (NULL);
	if (c == '0')
		return (game->map_textures[FLOOR_TEXTURE]);
	if (c == '1')
		return (game->map_textures[WALL_TEXTURE]);
	if (c == 'C')
	{
		if (game->collectible_frame >= COLLECTIBLE_FRAME)
			return (NULL);
		return (game->collectible_textures[game->collectible_frame]);
	}
	if (c == 'E')
	{
		if (game->map->collectibles == 0)
			return (game->map_textures[EXIT_OPEN_TEXTURE]);
		return (game->map_textures[EXIT_TEXTURE]);
	}
	return (NULL);
}

/**
 * Affiche une tuile spécifique (sol, objets, joueur).
 */
void	render_tile(t_game *game)
{
	char	c;
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			c = game->map->map[y][x];
			img = get_tile_image(game, c);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* TILE_SIZE, y * TILE_SIZE);
		}
		x++;
	}
	y++;
}

void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map_textures[PLAYER_TEXTURE], game->map->player_x * TILE_SIZE,
		game->map->player_y * TILE_SIZE);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map_textures[FLOOR_TEXTURE], game->map->player_x * TILE_SIZE,
		game->map->player_y * TILE_SIZE);
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	render_player(game);
}

int	animate_collectibles(t_game *game)
{
	static int	current_frame = 0;
	int			x;
	int			y;

	if (game->collectible_frame % 1000 == 0)
	{
		current_frame = (current_frame + 1) % COLLECTIBLE_FRAME;
		y = 0;
		while (y < game->map->height)
		{
			x = 0;
			while (x < game->map->width)
			{
				if (game->map->map[y][x] == 'C')
					mlx_put_image_to_window(game->mlx, game->win,
						game->collectible_textures[current_frame], x
						* TILE_SIZE, y * TILE_SIZE);
				x++;
			}
			y++;
		}
	}
	game->collectible_frame++;
	return (0);
}
