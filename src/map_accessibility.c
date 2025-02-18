/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:07:39 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/18 14:27:16 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "error_handling.h"
#include "so_long.h"

/**
 * Libère une copie de la carte.
 */
void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

/**
 * Remplit la carte en marquant les zones accessibles avec 'V'.
 */
void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/**
 * Copie la carte et vérifie les erreurs d'allocation.
 */
char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (map->height + 1));
	if (!map_copy)
		exit_with_map_error(map, "Failed to allocate memory for map copy", 0);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			exit_with_map_error(map, "Failed to duplicate map row", 0);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

/**
 * Vérifie si la carte est jouable après le flood fill.
 */
bool	is_map_solvable(char **map_copy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'E'))
		{
			free_map_copy(map_copy, map->height);
			exit_with_map_error(map,
				"Map is not solvable: unreachable collectibles or exit.", 0);
		}
		i++;
	}
	return (true);
}

/**
 * Vérifie si la carte est accessible depuis la position du joueur.
 */
bool	check_map_accessibility(t_map *map)
{
	char	**map_copy;

	map_copy = copy_map(map);
	flood_fill(map_copy, map->player_x, map->player_y);
	is_map_solvable(map_copy, map);
	free_map_copy(map_copy, map->height);
	return (true);
}
