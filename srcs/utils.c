/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:55 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/03 17:30:30 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(char *s, char *t)
{
	while (*s && (*s == *t))
	{
		s++;
		t++;
	}
	return (*s - *t);
}

int	ft_strcmp_end(char *s, char *t)
{
	if (ft_strlen(s) < ft_strlen(t))
		return (0);
	return (0 == ft_strcmp(&s[ft_strlen(s) - ft_strlen(t)], t));
}

int	ft_strncmp(char *s, char *t, int len)
{
	while (*s && (*s == *t) && (len != 0))
	{
		s++;
		t++;
		len--;
	}
	return (*s - *t);
}

int	is_found(int c, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}
