/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:03:19 by zakchouc          #+#    #+#             */
/*   Updated: 2024/02/23 14:03:58 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd)
{
	char	*read_buf;
	char	*str;
	int		read_len;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (NULL);
	read_len = 0;
	while (!ft_strchr(read_buf, '\n') && read_len >= 0)
	{
		read_len += read(fd, read_buf, BUFFER_SIZE);
		free(str);
		str = malloc(sizeof(char) * (read_len + 1));
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*clean_line(char *str)
{
	char *line;

	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buf;

	/* Error checks */
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &line, 0) < 0))
		return (NULL);

	/* Store read line until '\n' */
	line = ft_read_line(fd);

	/* Store everything read after '\n' */
	static_buf = ft_clean_line();

	return (line);
}

