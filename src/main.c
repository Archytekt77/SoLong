/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:37 by lmaria            #+#    #+#             */
/*   Updated: 2025/03/02 22:38:54 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

static bool	is_valid_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_valid_ber_file(argv[1]))
		exit_with_game_error(NULL, "Invalid map file. Please use a .ber file.",
			0);
	so_long_init(argv[1]);
	return (0);
}
