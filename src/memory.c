#include "../minilibx-linux/mlx.h"
#include "game.h"

/**
 * Libère la mémoire allouée pour la carte.
 */
void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
	{
		free(map);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
}

/**
 * Libère une copie temporaire de la carte (utilisée pour flood fill).
 */
void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

/**
 * Libère la mémoire allouée pour les textures.
 */
void	free_textures(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < TEXTURES_TAB)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
}

/**
 * Libère toutes les ressources du jeu proprement.
 */
void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
}
