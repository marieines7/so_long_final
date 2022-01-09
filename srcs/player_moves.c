/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:33:07 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/06 00:09:23 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	winning_winner_looser(int next_x, int next_y, t_game *game)
{
	if (game->map[next_y][next_x] == 'C')
	{
		game->player.collectibles = game->player.collectibles + 1;
		printf("Number of collectibles : %d\n", game->player.collectibles);
	}
	else if ((game->map[next_y][next_x] == 'E')
			&& (game->player.collectibles == game->total_collectibles))
	{
		printf("you win\n");
		exit_game(game);
	}
	else if (game->map[next_y][next_x] == 'V')
	{
		printf("you loose\n");
		exit_game(game);
	}
}

int	move_player(int next_x, int next_y, t_game *game)
{
	if ((game->map[next_y][next_x]) == '1' ||
			((game->map[next_y][next_x] == 'E')
			&& (game->player.collectibles < game->total_collectibles)))
		return (0);
	winning_winner_looser(next_x, next_y, game);
	game->player.orientation_x = next_x - game->player.curr_x;
	game->player.orientation_y = next_y - game->player.curr_y;
	game->player.curr_x = next_x;
	game->player.curr_y = next_y;
	game->map[game->player.curr_y][game->player.curr_x] = 'P';
	game->player.n_moves++;
	printf("Number of moves : %d\n", game->player.n_moves);
	game->map[game->player.prev_y][game->player.prev_x] = '0';
	game->player.prev_x = game->player.curr_x;
	game->player.prev_y = game->player.curr_y;
	return (0);
}

int	handle_player_moves(int keysym, t_game *game)
{
	if (keysym == ESC)
		exit_game(game);
	if ((keysym == UP) || (keysym == UP_W))
		move_player(game->player.curr_x, game->player.curr_y - 1, game);
	else if ((keysym == DOWN) || (keysym == DOWN_S))
		move_player(game->player.curr_x, game->player.curr_y + 1, game);
	else if ((keysym == LEFT) || (keysym == LEFT_A))
		move_player(game->player.curr_x - 1, game->player.curr_y, game);
	else if ((keysym == RIGHT) || (keysym == RIGHT_D))
		move_player(game->player.curr_x + 1, game->player.curr_y, game);
	return (0);
}

void	get_player_pos_and_collectibles(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = game->map;
	while (map[y] && y < game->win_height)
	{
		x = -1;
		while (map[y][++x] && x < game->win_width)
		{
			if (map[y][x] == 'P')
			{
				game->player.curr_x = x;
				game->player.curr_y = y;
			}
			if (map[y][x] == 'C')
				game->total_collectibles = game->total_collectibles + 1;
		}
		y++;
	}
}
