/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:37 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/19 14:09:51 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "system.h"

// bool	file_exists(char *filename)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error: Failed to open file");
// 		return (false);
// 	}
// 	close(fd);
// 	return (true);
// }

int	main(int argc, char **argv)
{

	if (argc != 2 || !strstr(argv[1], ".ber"))
		exit_with_game_error(NULL, "Invalid map file. Please use a .ber file.",
			0);
	// if (!file_exists(argv[1]))
	// 	return (1);
	so_long_init(argv[1]);
	
	return (0);
}
