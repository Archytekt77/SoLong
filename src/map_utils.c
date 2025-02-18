/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:32:58 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/13 04:41:43 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "error_handling.h"

// Vérifie si toutes les lignes de la carte ont la même largeur
bool	is_map_width_valid(t_map *map)
{
	int	current_width;
	int	i;

	i = 0;
	while (map->map[i])
	{
		current_width = ft_strlen(map->map[i]);
		if (current_width != map->width)
		{
			exit_with_map_error(map, "Map lines have inconsistent width", 0);
			return (false);
		}
		i++;
	}
	return (true);
}
