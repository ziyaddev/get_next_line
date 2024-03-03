/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:45:03 by zakchouc          #+#    #+#             */
/*   Updated: 2024/02/19 01:19:51 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Calculates the length of the string pointed to by s  */
size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if(!str)
		return (0);
	while (str[size])
		size++;
	return (size);
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
	free(s1);
	return (joined);
}

/* Returns a pointer to the first occurrence of C in S.  */
char	*ft_strchr(const char *s, int c)
{
	if (!*s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/* Returns a pointer to a new string which is a duplicate of the string s.  */
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		i = ft_strlen(s);
	else
		i = n;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (0);
	i = 0;
	while (s[i] && (i < n))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* Copies src string, null byte included, to dest.  */
char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	char	*copied;
// 	int		i;
//
// 	i = 0;
//
// 	copied[i] = 0;
// 	return (copied);
// }
//
// int	ft_read(int fd, char *buf, size_t bytes)
// {
//
// 	return (0);
// }
//
// Process : 
//	- read 4 bytes
//	- store them in str_buf
//	- process str_buf
//		- check if '\n' is found
//			- if found let everything before '\n' (included) in str_buf &
//				move everything after '\n' in static_buf
//			- if not found don't do anything
