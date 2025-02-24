/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:00 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/24 13:14:01 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "game.h"

/**
 * Libère la mémoire allouée pour la carte.
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

/**
 * Libère une copie temporaire de la carte (utilisée pour flood fill).
 */
void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

/**
 * Libère la mémoire allouée pour les textures.
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

/**
 * Libère toutes les ressources du jeu proprement.
 */
void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
