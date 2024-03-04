/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:33 by zakchouc          #+#    #+#             */
/*   Updated: 2024/02/21 14:42:43 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Write a function that returns a line read from a file descriptor
 * 				Allowed functions(s) : read, malloc, free
 * @param fd	The file descriptor to read from
 * @return		Read line : correct behavior 
 * 				NULL : there is nothing else to read, or an error occurred
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "get_next_line.h"

int	ft_count_until_newline(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i + 1);
	}
	return (0);
}

int	ft_read_line(int fd, char *line)
{
	if (line[0] != '\0')
		return (1);
	if (read(fd, line, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	static_buf[BUFFER_SIZE];
	int			newline_found;

	line = NULL;
	while ((!ft_count_until_newline(line))
		&& ft_read_line(fd, (char *)static_buf) > 0)
	{
		newline_found = ft_count_until_newline(static_buf);
		line = ft_strnjoin(line, static_buf, newline_found);
		if (!line)
			return (NULL);
		ft_memmove(static_buf, &static_buf[newline_found], newline_found);
	}
	return (line);
}

// int	main(void)
// {
// 	int				open_testfile_fd;
// 	char			*str_test =  "This is a string test !";
// 	int				line_nb;
//
// 	open_testfile_fd = open("./big_line_with_nl", O_RDONLY);
// 	if (open_testfile_fd < 0)
// 		return (-1);
//
// 	printf("Opened file descriptor : %d\n", open_testfile_fd);
// 	printf("\nstrlen : %ld\n", ft_strlen("my str len test"));
//
// 	printf("\nnull address : %p\n\n", &str_test[23]);
//
// 	line_nb = 0;
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
// 	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
//
// 	close(open_testfile_fd);
// 	return (0);
// }
