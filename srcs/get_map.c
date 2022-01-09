/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:17 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/09 16:49:57 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	s = (void *)malloc(count * size);
	i = 0;
	if (!s)
		return (NULL);
	while (i < count)
	{
		*(char *)(s + i) = 0;
		i++;
	}
	return (s);
}

void	map_size(int fd, t_game *game)
{
	int		y;
	int		x_max;
	char	**line;

	y = 0;
	x_max = 0;
	line = NULL;
	line = malloc(sizeof(char *) * 1000);
	line[y] = NULL;
	while (get_next_line(fd, &line[y]) > 0)
	{
		if (x_max == 0 || (x_max < ((int)ft_strlen(line[y]))))
			x_max = ft_strlen(line[y]);
		free(line[y]);
		line[y] = NULL;
		y++;
	}
	free(line[y]);
	line[y] = NULL;
	free(line);
	game->win_height = y;
	game->win_width = x_max;
}

void	allocate_map(t_game *game)
{
	if (game->win_height == 0 || game->win_width == 0)
	{
		printf("Error\nEmpty file\n");
		exit(0);
	}
	game->map = NULL;
	game->map = malloc((sizeof(char *) * (game->win_height + 1))
			+ (sizeof(char) * (game->win_height + 1) * (game->win_width + 1)));
	if (game->map == NULL)
		return (ft_putstr_fd("failed allocation\n", 1));
	return ;
}

void	get_map(int fd, t_game *game)
{
	int	l;

	l = 0;
	game->map[l] = NULL;
	while (get_next_line(fd, &game->map[l]) > 0)
	{
		l++;
		game->map[l] = NULL;
	}
	game->map[l + 1] = NULL;
}
