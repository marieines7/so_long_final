/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:43 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/09 17:26:52 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangular(char **line, int ymax, int xmax)
{
	int	m;
	int	first_line_len;

	m = 1;
	first_line_len = xmax;
	while (line[m] && (m < ymax))
	{
		if ((int)ft_strlen(line[m]) != first_line_len)
			return (0);
		m++;
	}
	return (1);
}

int	right_chars(char **map, int e, int c1, int p)
{
	int	l;
	int	c;

	l = -1;
	while (map[++l])
	{
		c = -1;
		while (map[l][++c])
		{
			if ((map[l][c] != '0') && (map[l][c] != '1')
			&& (map[l][c] != 'C') && (map[l][c] != 'P') && (map[l][c] != 'E'))
				return (0);
			if (map[l][c] == 'E')
				e++;
			else if (map[l][c] == 'C')
				c1++;
			else if (map[l][c] == 'P')
				p++;
		}
	}
	if ((e < 1) || (c1 < 1) || (p != 1))
		return (0);
	return (1);
}

int	walls(char **map, int ymax, int xmax)
{
	int	y;
	int	x;

	y = -1;
	if ((ymax <= 2) || (xmax <= 2))
		return (0);
	while (map[++y] && (y < ymax))
	{
		x = -1;
		while (map[y][++x] && (x < xmax))
		{
			if ((map[0][x]) != '1')
				return (0);
			if ((map[ymax - 1][x]) != '1')
				return (0);
			if ((map[y][0]) != '1')
				return (0);
			if (map[y][xmax - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	right_map(char **map, int ymax, int xmax)
{
	if (!is_rectangular(map, ymax, xmax))
	{
		ft_putstr_fd("unvalid map, not rectangular\n", 2);
		return (0);
	}
	if (!right_chars(map, 0, 0, 0))
	{
		ft_putstr_fd("need 1 P, at least 1C and 1 E\n", 2);
		return (0);
	}
	if (!walls(map, ymax, xmax))
	{
		ft_putstr_fd("unvalid map, walls need to be closed\n", 2);
		return (0);
	}
	return (1);
}
