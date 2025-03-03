/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:07:39 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 02:10:32 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Checks if the map is solvable after the flood fill.
 * If any collectibles ('C') or exit ('E') are left, the map is not solvable.
 */
static void	is_map_solvable(char **map_copy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'E'))
		{
			free_map_copy(map_copy, map->height);
			exit_with_map_error(map,
				"Map is not solvable. Collectibles or exit are unreachable.",
				0);
		}
		i++;
	}
}

/*
 * Performs a flood fill to mark accessible areas.
 */
static void	flood_fill(char **map, int x, int y)
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

/*
 * Creates a copy of the map and checks for allocation errors.
 */
static char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(map->height + 1, sizeof(char *));
	if (!map_copy)
		exit_with_map_error(map, "Failed to allocate memory for map copy", 1);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			exit_with_map_error(map, "Failed to duplicate map row", 1);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

/*
 * Checks if the map is accessible from the player's starting position.
 */
void	check_map_accessibility(t_map *map)
{
	char	**map_copy;

	map_copy = copy_map(map);
	flood_fill(map_copy, map->player_x, map->player_y);
	is_map_solvable(map_copy, map);
	free_map_copy(map_copy, map->height);
}
