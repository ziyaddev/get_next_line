/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:19 by zakchouc          #+#    #+#             */
/*   Updated: 2024/02/19 01:18:11 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strnjoin(char *s1, char *s2, size_t n);

int		ft_count_until_newline(char *str);

void	*ft_memmove(void *dest, const void *src, size_t n);

int		ft_read_line(int fd, char *line);

#endif
