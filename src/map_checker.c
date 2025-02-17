/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:04:52 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/17 17:51:56 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/so_long_bonus.h"
#include "error_handling.h"

/**
 * Vérifie si une ligne est totalement composée de murs ('1').
 */
bool	is_full_wall_line(char *line, int width)
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

/**
 * Vérifie si les bords de la carte sont fermés par des murs.
 */
bool	is_map_closed(t_map *map)
{
	int	i;

	if (!is_full_wall_line(map->map[0], map->width)
		|| !is_full_wall_line(map->map[map->height - 1], map->width))
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	printf("Map is closed by walls.\n");
	return (true);
}

/**
 * Vérifie et compte les éléments de la carte.
 */
bool	process_map_element(t_map *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->players++;
		map->player_x =	j;
		map->player_y = i;
		printf("📍 Joueur initialisé à (%d, %d)\n", map->player_x, map->player_y);
	}
	else if (c == 'E')
		map->exits++;
	else if (c == 'C')
		map->collectibles++;
	else if (c != '1' && c != '0')
		return (false);
	return (true);
}

// Vérifier les caractères valides et compter les éléments
bool	check_elements(t_map *map)
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
				return (false);
			j++;
		}
		i++;
	}
	ft_printf("Total Players: %d, Exits: %d, Collectibles: %d\n", map->players,
		map->exits, map->collectibles);
	return (map->players == 1 && map->exits == 1 && map->collectibles > 0);
}

// Fonction principale pour vérifier la validité de la carte
bool	check_map_validity(t_map *map)
{
	if (!is_map_closed(map))
		exit_with_map_error(map, "The map is not closed by walls.", 0);
	if (!check_elements(map))
		exit_with_map_error(map, "Invalid elements in the map.", 0);
	return (true);
}
