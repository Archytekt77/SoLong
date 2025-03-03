/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:00 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 02:13:53 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*
 * Frees the allocated memory for the map.
 */
void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->map[i])
			{
				free(map->map[i]);
				map->map[i] = NULL;
			}
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

/*
 * Frees a temporary copy of the map used for flood fill.
 */
void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (map_copy[i])
		{
			free(map_copy[i]);
			map_copy[i] = NULL;
		}
		i++;
	}
	free(map_copy);
	map_copy = NULL;
}

/*
 * Frees the textures allocated in the game.
 */
static void	free_textures(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < TEXTURES_TAB)
	{
		if (game->textures[i] != NULL)
		{
			mlx_destroy_image(game->mlx, game->textures[i]);
			game->textures[i] = NULL;
		}
		i++;
	}
}

/*
 * Frees all allocated resources in the game.
 */
void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}
