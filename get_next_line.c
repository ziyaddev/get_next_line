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

// To-do list :
// - Check max 'nmemb'& 'size' in  (int overflow)
//
// Required functions :
// strjoin	ok
// strchr	ok
// strlen	ok
// strdup	ok
// substr
// strlcpy

#include "get_next_line.h"

/* Set N bytes of S to C.  */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size || ((nmemb * size) > INT_MAX))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', (nmemb * size));
	return (ptr);
}

int	ft_count_until_newline(char *str)
{
	
	return (0);
}

// int	ft_read_line()
// {

// 	return (0);
// }

char	*get_next_line(int fd)
{
	char			*line;
	static char		*static_buf = "";


	return (line);
}

// int	main(void)
// {
// 	int				open_testfile_fd;
// 	char			*my_str;
// 	char			*mem_space;
// 	char			*calloc_mem_space;
// 	unsigned int	mem_space_len;
// 	int				calloc_size;
// 	char			*str_test =  "This is a string test !";
//
// 	my_str = malloc(sizeof(char) * 10);
// 	if (!my_str)
// 		return (-1);
//
// 	open_testfile_fd = open("./test.txt", O_RDONLY);
// 	if (open_testfile_fd < 0)
// 		return (-1);
//
// 	printf("Opened file descriptor : %d\n", open_testfile_fd);
// 	printf("\nstrlen : %ld\n", ft_strlen("my str len test"));
// 	printf("\nstrjoin : %s\n", ft_strjoin("my str len test\\", "|/ 2nd part"));
// 	printf("\nstrchr : %s\n", ft_strchr("salam akhi", 'k'));
//
// 	mem_space_len = 6;
// 	calloc_size = 6500;
//
// 	mem_space = ft_calloc(mem_space_len, calloc_size);
// 	calloc_mem_space = calloc(mem_space_len, calloc_size);
//
// 	for (size_t i = 0; i < mem_space_len; i++)
// 	{
// 		printf("ft_calloc memspace %ld : %c\t", i, mem_space[i]);
// 		printf("calloc memspace %ld : %c\n", i, calloc_mem_space[i]);
// 	}
//
// 	printf("\nmemspace : %s\n", mem_space);
//
// 	printf("ptr 'T' : %p\n", ft_strchr(str_test, 'T'));
// 	printf("ptr 'e' : %p\n", ft_strchr(str_test, 'e'));
//
// 	printf("\nstrndup test : %s\n\n", ft_strndup("salamouaalaikoum!", 44));
//
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
// 	printf("%s", get_next_line(open_testfile_fd));
//
// 	// write(1, "\nnext gnl ft\n", 13);
//
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
//
// 	// printf("\nstatic variable test %s\n", ft_static_variable_test());
// 	// printf("\nstatic variable test %s\n", ft_static_variable_test());
//
// 	free(mem_space);
// 	free(calloc_mem_space);
//
// 	close(open_testfile_fd);
// 	return (0);
// }
