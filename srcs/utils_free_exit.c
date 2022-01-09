/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:55 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/06 17:07:40 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	exit_error_fd(char *error, int fd)
{
	ft_putstr_fd("Error\n", fd);
	ft_putstr_fd(error, fd);
	exit (0);
}

void	free_gnl(char ***line)
{
	int	i;

	i = 0;
	if (*line == NULL)
		return ;
	while ((*line)[i])
	{
		free((*line)[i]);
		i++;
	}
	free((*line)[i]);
}
