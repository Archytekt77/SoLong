/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:52:31 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/19 02:43:32 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "game.h"
#include "system.h"
#include <errno.h>

void	exit_with_parsing_error(char *msg, int use_errno)
{
	if (use_errno)
		ft_printf("Error: %s: %s\n", msg, strerror(errno));
	else
		ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	exit_with_game_error(t_game *game, char *msg, int use_errno)
{
	exit_with_parsing_error(msg, use_errno);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	exit_with_map_error(t_map *map, char *msg, int use_errno)
{
	exit_with_parsing_error(msg, use_errno);
	if (map)
		free_map(map);
	exit(EXIT_FAILURE);
}
