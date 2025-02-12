/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:07:39 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/12 19:07:40 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "so_long.h"

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

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (map->height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		if (!map_copy[i])
		{
			// free_map_copy(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

bool	is_map_solvable(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'E'))
		{
			ft_printf("Error\nMap is not solvable: unreachable collectibles \
                or exit.\n");
			return (false);
		}
		// free(map_copy[i]);
		i++;
	}
	// free(map_copy);
	return (true);
}

bool	check_map_accessibility(t_map *map)
{
	char	**map_copy;

	map_copy = copy_map(map);
	if (!map_copy)
		return (false);
	flood_fill(map_copy, map->player_x, map->player_y);
	if (!is_map_solvable(map_copy, map->height))
	{
		free_map_copy(map_copy, map->height);
		free_map(map);
		exit(1);
	}
	free_map_copy(map_copy, map->height);
	return (true);
}
