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
	int		read_status;


	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (NULL);
	read_status = read(fd, read_buf, BUFFER_SIZE);

	return (read_buf);
}

char	*get_line(char *str)
{
	char *line;

	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, line, 0) < 0))
			return (NULL);

	line = ft_read_line(fd);

	return (line);
}

