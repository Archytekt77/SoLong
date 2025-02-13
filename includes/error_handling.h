#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "so_long.h"

void	free_game(t_game *game);
void	free_map(t_map *map);
void	free_textures(t_game *game);
void	exit_with_map_error(t_map *map, char *msg, int use_errno);
void	exit_with_game_error(t_game *game, char *msg, int use_errno);

#endif