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
