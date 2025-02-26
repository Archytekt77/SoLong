/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:53:36 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/26 13:04:58 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "game.h"

void	free_game(t_game *game);
void	free_map(t_map *map);
void	free_map_copy(char **map_copy, int height);

void	exit_with_map_error(t_map *map, char *msg, int use_errno);
void	exit_with_game_error(t_game *game, char *msg, int use_errno);

#endif