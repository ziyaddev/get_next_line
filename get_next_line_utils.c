/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:45:03 by zakchouc          #+#    #+#             */
/*   Updated: 2024/03/05 00:41:49 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < BUFFER_SIZE)
	{
		if (n && i < BUFFER_SIZE - n)
			((char *)dest)[i] = ((char *)src)[i];
		else
			((char *)dest)[i] = '\0';
	}
	return (dest);
}

// int	ft_count_until_newline(char *str)
// {
// 	int	i;

// 	i = -1;
// 	if (!str)
// 		return (0);
// 	while (str[++i])
// 	{
// 		if (str[i] == '\n')
// 			return (i + 1);
// 	}
// 	return (0);
// }

// int	ft_read_line(int fd, char *line)
// {
// 	if (line[0] != '\0')
// 		return (1);
// 	if (read(fd, line, BUFFER_SIZE) > 0)
// 		return (1);
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	static_buf[BUFFER_SIZE];
// 	int			newline_found;

// 	line = NULL;
// 	while ((!ft_count_until_newline(line))
// 		&& ft_read_line(fd, (char *)static_buf) > 0)
// 	{
// 		newline_found = ft_count_until_newline(static_buf);
// 		line = ft_strnjoin(line, static_buf, newline_found);
// 		if (!line)
// 			return (NULL);
// 		ft_memmove(static_buf, &static_buf[newline_found], newline_found);
// 	}
// 	return (line);
// }