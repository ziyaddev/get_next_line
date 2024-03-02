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

/* Used to store everything before '\n' */
char	*ft_read_line(char *line)
{
	char		*newline;
	size_t		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	newline = ft_strndup(line, i);
	if (!newline)
		return (free(newline), NULL); // return (free(someleak), NULL);
	return (newline);
}

char	*ft_clean_next_line(char *line)
{
	char	*newline_found;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newline_found = ft_strchr(line, '\n');
	if (!newline_found)
		return (NULL);
	newline_found++;
	while (newline_found[j])
		j++;
	buf = ft_calloc((j + 1), sizeof(char));
	if (!buf)
		return (free(buf), NULL);
	j = 0;
	while (newline_found[i])
	{
		buf[j] = newline_found[i];
		i++;
		j++;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buf = "";
	char		*line_buf;
	int			read_status;

	/* Error checks */
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &line, 0) < 0))
		return (NULL);
	line_buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line_buf)
		return (NULL);
	read_status = 1;
	while (!ft_strchr(static_buf, '\n') && read_status != 0)
	{
		read_status = read(fd, line_buf, BUFFER_SIZE);
		if (read_status == -1)
			return (free(line_buf), NULL);
		static_buf = ft_strjoin(static_buf, line_buf);
	}
	free(line_buf);
	line_buf = ft_read_line(static_buf);
	static_buf = ft_clean_next_line(static_buf);
	return (line_buf);
}
