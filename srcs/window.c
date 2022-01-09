/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:18:21 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/06 18:35:42 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_game *game)
{
	printf("Nb of collectibles : %d out of %d\n",
		game->player.collectibles, game->total_collectibles);
	free_sprites(game);
	mlx_destroy_image(game->mlx.ptr, game->img.xpm);
	mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.ptr);
	game->mlx.win = NULL;
	free(game->mlx.ptr);
	free_gnl(&game->map);
	free(game->map);
	exit(1);
	return (0);
}

int	game_display(t_game *game)
{
	draw(game);
	move_player(0, 0, game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.xpm, 0, 0);
	return (0);
}

int	calculpas(t_game *game)
{
	int	x;
	int	y;
	int	pas1;
	int	pas2;

	mlx_get_screen_size(game->mlx.ptr, &x, &y);
	pas1 = x / game->win_width;
	pas2 = y / game->win_height;
	if (pas1 < pas2)
		return (pas1);
	else
		return (pas2);
}

void	view_tab(char **s)
{
	if (s)
	{
		while (*s)
		{
			printf("%s \n", *s);
			s++;
		}
	}
}

void	window_display(t_game *game)
{
	int	j;

	load_sprites(game);
	j = calculpas(game);
	game->bpp = j;
	game->width = j * game->win_width;
	game->height = j * game->win_height;
	game->mlx.win = mlx_new_window(game->mlx.ptr,
			game->width, game->height, "PacMan");
	game->img.xpm = mlx_new_image(game->mlx.ptr, game->width, game->height);
	game->img.data = mlx_get_data_addr(game->img.xpm,
			&(game->img.bits_per_pixel),
			&(game->img.line_len), &(game->img.endian));
	mlx_key_hook(game->mlx.win, handle_player_moves, game);
	mlx_hook(game->mlx.win, 33, (1L << 17), exit_game, game);
	mlx_loop_hook(game->mlx.ptr, game_display, game);
	mlx_loop(game->mlx.ptr);
}
