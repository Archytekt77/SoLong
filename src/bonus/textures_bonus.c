#include "../includes/Libft/libft.h"
#include "../includes/error_handling.h"
#include "../includes/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <limits.h>
#include <unistd.h>

/**
 * Construit un chemin de fichier à partir d'un chemin de base et d'un index.
 */
void	build_filename(char *dest, const char *base, int index)
{
	int	len;

	len = 0;
	while (base[len])
	{
		dest[len] = base[len];
		len++;
	}
	dest[len++] = '/';
	if (strstr(base, "idle"))
	{
		dest[len++] = 'i';
		dest[len++] = 'd';
		dest[len++] = 'l';
		dest[len++] = 'e';
	}
	else if (strstr(base, "run"))
	{
		dest[len++] = 'r';
		dest[len++] = 'u';
		dest[len++] = 'n';
	}
	else if (strstr(base, "death"))
	{
		dest[len++] = 'd';
		dest[len++] = 'e';
		dest[len++] = 'a';
		dest[len++] = 't';
		dest[len++] = 'h';
	}
	dest[len++] = '_';
	if (index < 10)
		dest[len++] = '0';
	dest[len++] = '0' + index;
	dest[len++] = '.';
	dest[len++] = 'x';
	dest[len++] = 'p';
	dest[len++] = 'm';
	dest[len] = '\0';
	printf("✅ Chemin généré : %s\n", dest); // Vérifier le bon chemin généré
}

/**
 * Charge une série de textures animées dans un tableau.
 */
bool	load_animation(void *mlx, void **frames, const char *base_path,
		int frame_count)
{
	int		i;
	int		width;
	int		height;
	char	filename[128];

	i = 0;
	while (i < frame_count)
	{
		build_filename(filename, base_path, i);
		printf("🔍 Tentative de chargement : %s\n", filename);
		printf("🔍 Vérification d'existence : ");
		system("ls -l textures/player/idle/");
		frames[i] = mlx_xpm_file_to_image(mlx, filename, &width, &height);
		if (!frames[i])
		{
			printf("❌ Échec du chargement : %s\n", filename);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * Récupère le chemin absolu du dossier textures.
 */
void	get_absolute_texture_path(char *dest, const char *subfolder)
{
	char	cwd[PATH_MAX];

	// Récupérer le répertoire courant
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		sprintf(dest, "%s/textures/player/%s", cwd, subfolder);
	}
	else
	{
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
}

/**
 * Charge toutes les textures du jeu, y compris les animations du joueur.
 */
bool	load_textures(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	absolute_path[PATH_MAX];

	i = 0;
	printf("🔍 Chargement de : %s\n", "textures/wall.xpm");
	game->textures[WALL_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->textures[FLOOR_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures[PLAYER_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->textures[COLLECTIBLE_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures[EXIT_TEXTURE] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	while (i < 5)
	{
		if (!game->textures[i])
		{
			if (i == 0)
				printf("❌ Échec du chargement : %s\n", "textures/wall.xpm");
			else if (i == 1)
				printf("❌ Échec du chargement : %s\n", "textures/floor.xpm");
			else if (i == 2)
				printf("❌ Échec du chargement : %s\n", "textures/player.xpm");
			else if (i == 3)
				printf("❌ Échec du chargement : %s\n",
					"textures/collectible.xpm");
			else if (i == 4)
				printf("❌ Échec du chargement : %s\n", "textures/exit.xpm");
			exit_with_game_error(game, "Failed to load texture", 0);
		}
		i++;
	}
	// Charger Idle
	get_absolute_texture_path(absolute_path, "idle");
	if (!load_animation(game->mlx, game->player_idle, absolute_path, 4))
		exit_with_game_error(game, "Failed to load Idle animation", 0);
	// Charger Run
	get_absolute_texture_path(absolute_path, "run");
	if (!load_animation(game->mlx, game->player_run, absolute_path, 6))
		exit_with_game_error(game, "Failed to load Run animation", 0);
	// Charger Death
	get_absolute_texture_path(absolute_path, "death");
	if (!load_animation(game->mlx, game->player_death, absolute_path, 6))
		exit_with_game_error(game, "Failed to load Death animation", 0);
	// // if (!load_animation(game->mlx, game->player_idle, "textures/player/idle",
	// // 		4))
	// // 	exit_with_game_error(game, "Failed to load Idle animation", 0);
	// // if (!load_animation(game->mlx, game->player_run, "textures/player/run",
	// 		6))
	// // 	exit_with_game_error(game, "Failed to load Run animation", 0);
	// // if (!load_animation(game->mlx, game->player_death,
	// 		"textures/player/death",
	// // 		6))
	// // 	exit_with_game_error(game, "Failed to load Death animation", 0);
	return (true);
}
