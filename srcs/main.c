/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:11:10 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/09 17:36:27 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	save_map(char **map, t_game *game, int height, int width)
{
	int	i;
	int	line;

	line = 0;
	game->map = (char **)malloc(sizeof(char *) * (height + 1));
	while (line <= height)
		game->map[line++] = (char *)malloc(sizeof(char) * (width + 1));
	line = 0;
	i = 0;
	while (game->map[line] && (line < height))
	{
		i = 0;
		while (game->map[line][i] && (i < width))
		{
			game->map[line][i] = map[line][i];
			i++;
		}
		line++;
	}
}

void	init_struct(t_game *game, char **map, int height, int width)
{
	game->bpp = 32;
	game->map = NULL;
	game->height = height * game->bpp;
	game->width = width * game->bpp;
	game->map = map;
	game->player.collectibles = 0;
	game->total_collectibles = 0;
	get_player_pos_and_collectibles(game);
	game->player.prev_x = game->player.curr_x;
	game->player.prev_y = game->player.curr_y;
	game->player.orientation_x = 0;
	game->player.orientation_y = 0;
	game->player.n_moves = 0;
	game->mlx.ptr = mlx_init();
}

void	init_values(t_game *game)
{
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->img.width = 0;
	game->img.height = 0;
	game->img.xpm = 0;
	game->ground.xpm = 0;
	game->wall.xpm = 0;
	game->collectible.xpm = 0;
	game->exit.xpm = 0;
	game->pacman_left.xpm = 0;
	game->pacman_right.xpm = 0;
	game->pacman_up.xpm = 0;
	game->pacman_down.xpm = 0;
}

void	get_rightfile_mapinfo(char **av, t_game *game)
{
	int	fd;

	fd = open(av[1], O_WRONLY);
	if ((fd == -1)
		|| ((!ft_strcmp_end(av[1], ".ber"))))
		exit_error_fd("please get an actual .ber file\n", 2);
	close(fd);
	fd = open(av[1], O_RDONLY);
	map_size(fd, game);
	close(fd);
	allocate_map(game);
	fd = open(av[1], O_RDONLY);
	get_map(fd, game);
	close(fd);
}

int	main(int ac, char **av)
{
	t_game	game;

	init_values(&game);
	if (ac == 2)
	{
		get_rightfile_mapinfo(av, &game);
		if (right_map(game.map, game.win_height, game.win_width))
		{
			init_struct(&game, game.map, game.win_height, game.win_width);
			window_display(&game);
		}
		else
		{
			free_gnl(&game.map);
			free(game.map);
			exit(0);
		}
	}
	else
		ft_putstr_fd("Error, get a ber file \n", 2);
	return (0);
}
