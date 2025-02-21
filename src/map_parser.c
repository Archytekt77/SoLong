/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:11:52 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/21 18:43:06 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "game.h"
#include "system.h"

// Lit une ligne et enlève le '\n' à la fin si nécessaire
bool	read_map_line(int fd, t_map *map, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free(line);
		return (false);
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map->map[i] = line;
	return (true);
}

// Remplit `map->map` avec `get_next_line`
bool	fill_map(t_map *map, char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (!read_map_line(fd, map, i))
			return (false);
		i++;
	}
	close(fd);
	return (true);
}

// Compte le nombre de lignes dans le fichier
int	count_lines(char *filename)
{
	char	*line;
	int		fd;
	int		lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

// Initialise la structure map
t_map	*init_map_structure(t_map *map, char *filename)
{
	int	i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		exit_with_map_error(map, "Failed to allocate memory for map structure",
			0);
	map->height = count_lines(filename);
	if (map->height <= 0)
	{
		map->map = NULL;
		exit_with_map_error(map, "Invalid map height", 0);
	}
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		exit_with_map_error(map, "Failed to allocate memory for map", 0);
	while (i < map->height + 1)
	{
		map->map[i] = NULL;
		i++;
	}
	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
	return (map);
}

// Fonction principale pour parser la carte
t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = NULL;
	map = init_map_structure(map, filename);
	if (!fill_map(map, filename))
		exit_with_map_error(map, "Failed to read map file", 0);
	if (!is_map_width_valid(map))
		exit_with_map_error(map, "Invalid map width", 0);
	return (map);
}
