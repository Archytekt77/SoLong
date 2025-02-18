/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:52:31 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 18:19:33 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/minilibx-linux/mlx.h"
#include "so_long.h"
#include <errno.h>

/**
 * Libère la mémoire allouée pour la carte
 */
void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
	{
		free(map);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
}

/**
 * Libère la mémoire allouée pour les textures de collectibles
 */
void	free_collectible_textures(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 13)
	{
		if (game->collectible_textures[i])
			mlx_destroy_image(game->mlx, game->collectible_textures[i]);
		i++;
	}
}

/**
 * Libère la mémoire allouée pour les textures de map
 */
void	free_map_textures(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 6)
	{
		if (game->map_textures[i])
			mlx_destroy_image(game->mlx, game->map_textures[i]);
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
	free_map_textures(game);
	free_collectible_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
}

/**
 * Affiche un message d'erreur et quitte le programme.
 * Si use_errno est à 1, affiche le message système correspondant à errno.
 */
void	exit_with_game_error(t_game *game, char *msg, int use_errno)
{
	if (use_errno)
		ft_printf("Error: %s: %s\n", msg, strerror(errno));
	else
		ft_printf("Error: %s\n", msg);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	exit_with_map_error(t_map *map, char *msg, int use_errno)
{
	if (use_errno)
		ft_printf("Error: %s: %s\n", msg, strerror(errno));
	else
		ft_printf("Error: %s\n", msg);
	if (map)
		free_map(map);
	else
		ft_printf("Warning: `map` is NULL, nothing to free.\n");
	exit(EXIT_FAILURE);
}
