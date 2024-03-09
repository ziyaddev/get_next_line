/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:33 by zakchouc          #+#    #+#             */
/*   Updated: 2024/03/05 00:41:40 by zakchouc         ###   ########.fr       */
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

/* Calculates the length of the string pointed to by s  */
size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str_ptr;

	str_ptr = (char *)s;
	while (*str_ptr)
	{
		if (*str_ptr == (char) c)
			return (str_ptr);
		str_ptr++;
	}
	if (*str_ptr == (char) c)
		return (str_ptr);
	return ((void *)0);
}

/* Allocates and returns concatenation of ’s1’ and ’s2’ as string.  */
char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	if (n)
		s2_len = n;
	else
		s2_len = ft_strlen(s2);
	joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (free(s1), NULL);
	joined[s1_len + s2_len] = '\0';
	while (s2_len--)
		joined[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		joined[s1_len] = s1[s1_len];
	// free(s1);
	return (joined);
}

char	*ft_read_line(int fd, int *read_status)
{
	char	*read_buf;

	read_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buf)
		return (NULL);
	*read_status = read(fd, read_buf, BUFFER_SIZE);
	return (read_buf);
}

char	*ft_process(char *static_buf, char *line)
{
	char	*newline_found;

	newline_found = ft_strchr(static_buf, '\n');
	line = ft_strndup(static_buf, (newline_found - static_buf + 1));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*read_buf;
	static char	*static_buf = "";
	char		*newline_found;
	int			read_status;

	line = NULL;
	newline_found = ft_strchr(static_buf, '\n');
	if (ft_strchr(static_buf, '\n'))
	{
		line = ft_process(static_buf, line);
		static_buf = ft_strndup((newline_found + 1), ft_strlen(newline_found + 1));
		return (line);
	}
	while (!ft_strchr(static_buf, '\n'))
	{
		read_buf = ft_read_line(fd, &read_status);
		static_buf = (ft_strnjoin(static_buf, read_buf, BUFFER_SIZE));
		free(read_buf);
		newline_found = ft_strchr(static_buf, '\n');
		if (!read_status)
			return (NULL);
		else if (newline_found)
		{
			line = ft_process(static_buf, line);
			static_buf = ft_strndup((newline_found + 1), ft_strlen(newline_found + 1));
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int				open_testfile_fd;
	char			*str_test =  "This is a string test !";
	int				line_nb;

	open_testfile_fd = open("./test.txt", O_RDONLY);
	if (open_testfile_fd < 0)
		return (-1);

	printf("Opened file descriptor : %d\n", open_testfile_fd);
	printf("\nstrlen : %ld\n", ft_strlen("my str len test"));

	printf("\nnull address : %p\n\n", &str_test[23]);

	line_nb = 0;
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));
	printf("[%d] - %s", ++line_nb, get_next_line(open_testfile_fd));

	printf("\nend of main\n");
	close(open_testfile_fd);
	return (0);
}
