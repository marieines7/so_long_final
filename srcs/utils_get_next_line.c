/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:48:44 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/09 17:42:39 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		k;
	int		i;
	char	*dst;

	k = 0;
	i = 0;
	if (!(s1))
		return (ft_strdup(s2));
	if (!(s2))
		return (ft_strdup(s1));
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		dst[i + k] = s2[k];
		k++;
	}
	dst[i + k] = '\0';
	return (dst);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		return (NULL);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (-1);
	while (*str != c)
	{
		if (*str == '\0')
			return (-1);
		str++;
	}
	return (str - s);
}
