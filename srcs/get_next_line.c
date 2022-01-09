/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:48:34 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/09 17:36:46 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ret_line(char **backup, char **line, int nl_len)
{
	char	*temp;

	(*backup)[nl_len] = '\0';
	*line = ft_strdup(*backup);
	temp = ft_strdup(&((*backup)[nl_len + 1]));
	free(*backup);
	*backup = NULL;
	*backup = temp;
	return (1);
}

int	ret_last_line(char **backup, char **line, int len_read)
{
	int		nl_len;

	if (len_read < 0)
		return (-1);
	nl_len = ft_strchr(*backup, '\n');
	if (*backup && (nl_len >= 0))
		return (ret_line(backup, line, nl_len));
	else if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[MAX_FD];
	char		buf[BUFFER_SIZE + 1];
	int			len_read;
	int			nl_len;
	char		*temp;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0))
		return (-1);
	len_read = read(fd, buf, BUFFER_SIZE);
	while (len_read > 0)
	{
		buf[len_read] = '\0';
		temp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = NULL;
		backup[fd] = temp;
		nl_len = ft_strchr(backup[fd], '\n');
		if (nl_len >= 0)
			return (ret_line(&backup[fd], line, nl_len));
	}
	return (ret_last_line(&backup[fd], line, len_read));
}
