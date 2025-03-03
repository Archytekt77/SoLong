/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:07:11 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/03 02:02:28 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

/*
 * Checks if the tile the player is trying to move to has any effect.
 */
static bool	check_tile_effect(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (!game || !game->map || !game->map->map)
		exit_with_game_error(game, "Invalid game state in check_tile_effect.",
			0);
	tile = game->map->map[new_y][new_x];
	if (tile == '1')
		return (false);
	if (tile == 'C')
	{
		ft_printf("You collected an item!\n");
		game->map->collectibles--;
	}
	if (tile == 'E')
	{
		if (game->map->collectibles > 0)
		{
			ft_printf("You must collect all items before exiting!\n");
			return (false);
		}
		ft_printf("You won in %d moves!\n", game->moves + 1);
		close_window(game);
	}
	return (true);
}

/*
 * Moves the player to the new position.
 */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	if (!game || !game->map || !game->map->map || !game->mlx || !game->win)
		exit_with_game_error(game, "Invalid game state in move_player.", 0);
	new_x = game->map->player_x + dx;
	new_y = game->map->player_y + dy;
	if (!check_tile_effect(game, new_x, new_y))
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->textures[FLOOR_TEXTURE],
		game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_player(game);
}
