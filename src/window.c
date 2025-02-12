/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:13 by archytekt         #+#    #+#             */
/*   Updated: 2025/02/12 19:19:14 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft/libft.h"
#include "../includes/minilibx-linux/mlx.h"
#include "so_long.h"

void	free_textures(t_game *game)
{
	for (int i = 0; i < 5; i++)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
	}
}

static void	free_game_resources(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->textures)
		free_textures(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
}

bool	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to initialize MiniLibX\n");
		return (false);
	}
	game->win = mlx_new_window(game->mlx, game->map->width * 128,
			game->map->height * 128, "So Long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		free_game_resources(game);
		return (false);
	}
	if (!load_textures(game))
	{
		ft_printf("Error\nFailed to load textures\n");
		free_game_resources(game);
		return (false);
	}
	render_map(game);
	return (true);
}

int	close_window(t_game *game)
{
	free_game_resources(game);
	ft_printf("Game closed.\n");
	exit(0);
	return (0);
}
