#include "../includes/Libft/libft.h"
#include "so_long.h"

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
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
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
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
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
		free_map(map);
		exit(1);
	}
	return (true);
}
