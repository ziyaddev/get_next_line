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

/* Calculates the length of the string pointed to by s  */
size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

/* Allocates and returns concatenation of ’s1’ and ’s2’ as string.  */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = 0;
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
