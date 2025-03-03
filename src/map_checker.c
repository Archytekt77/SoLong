/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:52 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 01:15:54 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Checks and counts the elements in the map.
 */
static bool	process_map_element(t_map *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->players++;
		map->player_x = j;
		map->player_y = i;
	}
	else if (c == 'E')
		map->exits++;
	else if (c == 'C')
		map->collectibles++;
	else if (c != '1' && c != '0')
		return (false);
	return (true);
}

/*
 * Checks if the map contains the correct number of required elements.
 */
static void	check_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!process_map_element(map, map->map[i][j], i, j))
				exit_with_map_error(map, "The map contains invalid characters.",
					0);
			j++;
		}
		i++;
	}
	if (map->players != 1)
		exit_with_map_error(map, "The map must have exactly one player ('P').",
			0);
	if (map->exits != 1)
		exit_with_map_error(map, "The map must have exactly one exit ('E').",
			0);
	if (map->collectibles == 0)
		exit_with_map_error(map,
			"The map must have at least one collectible ('C').", 0);
}

/*
 * Checks if a line consists entirely of walls ('1').
 */
static bool	is_full_wall_line(char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

/*
 * Checks if the map is properly enclosed by walls.
 */
static void	is_map_closed(t_map *map)
{
	int	i;

	if (!is_full_wall_line(map->map[0], map->width)
		|| !is_full_wall_line(map->map[map->height - 1], map->width))
		exit_with_map_error(map,
			"Map's top & bottom sides must be enclosed by walls ('1').", 0);
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			exit_with_map_error(map,
				"Map's left & right sides must be enclosed by walls ('1').", 0);
		i++;
	}
}

/*
 * Main function to verify the validity of the map.
 */
void	check_map_validity(t_map *map)
{
	is_map_closed(map);
	check_elements(map);
}
