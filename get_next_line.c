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
	char	*str2;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (NULL);
	read_len = 0;
	while (!ft_strchr(read_buf, '\n') && !(read_len < 0))
	{
		read_len += read(fd, read_buf, BUFFER_SIZE);
		str = malloc(sizeof(char) * (read_len + 1));
		if (!str)
			return (NULL); // return (free(someleak), NULL);
		str2 = ft_strndup(str, ft_strlen(str));
		free(str);
		str = ft_strjoin(str2, read_buf);
	}
	free(read_buf);
	free(str2);
	return (str);
}

char	*ft_clean_line(char *line, size_t *line_len)
{
	char	*newline_found;
	char	*buf;

	newline_found = ft_strchr(line, '\n');
	buf = malloc(sizeof(char) * ((newline_found - line + 1) + 1));
	if (!buf)
		return (NULL);
	*line_len += newline_found - line + 1;
	newline_found++;
	return (newline_found);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buf = "";
	size_t		line_len;
	char		*line_buf;

	/* Error checks */
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &line, 0) < 0))
		return (NULL);

	/* Store read line until '\n' found */
	line_buf = ft_read_line(fd);
	if (ft_strchr(line_buf, '\n'))
	{
		line_len = ft_strlen(static_buf);
		static_buf = ft_strjoin(static_buf, ft_clean_line(line_buf, &line_len));
		printf("\nstatic buf : %s\n", static_buf);
		line = malloc(sizeof(char) * (line_len + 1));
		if (!line)
			return (NULL);
		line = ft_strndup(line_buf, line_len);
		free(line_buf);
	}
	/*  */
	/* Store everything read after '\n' */
	// static_buf = ft_clean_line();

	return (line);
}
