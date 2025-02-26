/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:37 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/26 13:58:54 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "game.h"
#include "system.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		exit_with_game_error(NULL, "Invalid map file. Please use a .ber file.",
			0);
	so_long_init(argv[1]);
	return (0);
}
