/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:50:32 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/17 18:46:24 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

/**
 * Retourne l'image correspondant à un élément de la carte.
 */
void	*get_tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->textures[0]);
	if (c == 'C')
		return (game->textures[3]);
	if (c == 'E')
		return (game->textures[4]);
	printf("❌ Erreur : Aucun sprite trouvé pour '%c'\n", c);
	return (NULL);
}

/**
 * Affiche une tuile spécifique (sol, objets, joueur avec animation).
 */
void	render_tile(t_game *game, int x, int y)
{
	char	c;
	void	*img;
	void	*player_img;

	printf("🔍 Affichage de la tuile (%d, %d)\n", x, y);
	printf("🎯 Position actuelle du joueur : (%d, %d)\n", game->map->player_x,
		game->map->player_y);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x
		* TILE_SIZE, y * TILE_SIZE);
	c = game->map->map[y][x];
	img = get_tile_image(game, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
			* TILE_SIZE);
	if (game->map->player_x == x && game->map->player_y == y)
	{
		player_img = game->player_idle[game->current_frame_idle];
		if (!player_img)
			printf("❌ Erreur: Aucun sprite du joueur à (%d, %d)\n", x, y);
		else
		{
			printf("✅ Affichage joueur à (%d, %d)\n", x, y);
			mlx_put_image_to_window(game->mlx, game->win, player_img, x
				* TILE_SIZE, y * TILE_SIZE);
		}
	}
}

/**
 * Affiche toute la carte.
 */
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

/**
 * Gère l'animation du joueur en changeant les frames.
 */
int	animate_player(void *param)
{
	t_game		*game;
	static int	frame_counter = 0;

	game = (t_game *)param;
	frame_counter++;
	if (frame_counter > 30000)
	{
		game->current_frame_idle = (game->current_frame_idle + 1) % 4;
		frame_counter = 0;
		printf("🌀 Animation frame updated: idle = %d",
			game->current_frame_idle);
	}
	return (0);
}
