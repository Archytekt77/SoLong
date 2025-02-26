/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:52:31 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/26 13:58:31 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "game.h"
#include "system.h"
#include <errno.h>

static void	exit_with_parsing_error(char *msg, int use_errno)
{
	if (use_errno)
		ft_printf("Error: %s: %s\n", msg, strerror(errno));
	else
		ft_printf("Error: %s\n", msg);
}

/*
 * Prints an error message and exits the game.
 */
void	exit_with_game_error(t_game *game, char *msg, int use_errno)
{
	exit_with_parsing_error(msg, use_errno);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

/*
 * Prints an error message and exits due to a map-related error.
 */
void	exit_with_map_error(t_map *map, char *msg, int use_errno)
{
	exit_with_parsing_error(msg, use_errno);
	if (map)
		free_map(map);
	exit(EXIT_FAILURE);
}
