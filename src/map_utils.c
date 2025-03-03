/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:32:58 by archytekt         #+#    #+#             */
/*   Updated: 2025/03/03 00:48:50 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

/*
 * Checks if all rows in the map have the same width.
 */
void	is_map_width_valid(t_map *map)
{
	int	current_width;
	int	i;

	if (!map || !map->map || !map->map[0])
		exit_with_map_error(map, "Map data is invalid", 0);
	map->width = ft_strlen(map->map[0]);
	i = 1;
	while (map->map[i])
	{
		current_width = ft_strlen(map->map[i]);
		if (current_width != map->width)
			exit_with_map_error(map, "Map is not rectangular", 0);
		i++;
	}
}
