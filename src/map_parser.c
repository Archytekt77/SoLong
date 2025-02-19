/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:11:52 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/19 22:07:02 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "game.h"
#include "system.h"

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

// Lit une ligne et enlève le '\n' à la fin si nécessaire
bool	read_map_line(int fd, t_map *map, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		free_map(map);
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
		exit_with_map_error(map, "Failed to open file", 1);
	i = 0;
	while (i < map->height)
	{
		if (!read_map_line(fd, map, i))
			exit_with_map_error(map, "Error reading map file", 0);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (true);
}

// Initialise la structure map
bool	init_map_structure(t_map *map, char *filename)
{
	map->height = count_lines(filename);
	if (map->height <= 0)
	{
		map->map = NULL;
		return (false);
	}
	// exit_with_map_error(map, "Invalid map file", 0);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		exit_with_map_error(map, "Failed to allocate memory for map", 0);
	return (true);
}

// Fonction principale pour parser la carte
t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_with_map_error(NULL, "Memory allocation failed", 0);
	if (!init_map_structure(map, filename))
	{
		free(map);
		return (NULL);
	}
	// exit_with_map_error(map, "Failed to initialize map structure", 0);
	if (!fill_map(map, filename))
		exit_with_map_error(map, "Failed to read map file", 0);
	map->width = ft_strlen(map->map[0]);
	if (!is_map_width_valid(map))
		exit_with_map_error(map, "Invalid map width", 0);
	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
	return (map);
}
