/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:11:52 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 01:35:12 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Reads a line from the file and removes the trailing newline.
 */
static bool	read_map_line(int fd, t_map *map, int i)
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

/*
 * Fills the map structure using `get_next_line`.
 */
static void	fill_map(t_map *map, char *filename)
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
		{
			close(fd);
			exit_with_map_error(map, "Error reading map file", 0);
		}
		i++;
	}
	close(fd);
}

/*
 * Counts the number of lines in the map file..
 */
static int	count_lines(t_map *map, char *filename)
{
	char	*line;
	int		fd;
	int		lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_map_error(map, "Failed to open file", 1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (lines == 0)
		exit_with_map_error(map, "The map file is empty", 0);
	return (lines);
}

/*
 * Initializes the map structure.
 */
static t_map	*init_map_structure(char *filename)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_with_map_error(map, "Failed to allocate memory for map structure",
			1);
	map->height = count_lines(map, filename);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		exit_with_map_error(map, "Failed to allocate memory for map", 1);
	return (map);
}

/*
 * Main function to parse the map from a file.
 */
t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = init_map_structure(filename);
	fill_map(map, filename);
	is_map_width_valid(map);
	if (map->width <= 0 || map->height <= 0)
		exit_with_map_error(map, "Invalid map dimensions.", 0);
	return (map);
}
