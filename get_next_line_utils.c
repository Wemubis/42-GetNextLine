/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:31 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/22 15:38:18 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// check if "\n"
int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (!s[i] && c == '\0')
		return (1);
	return (0);
}

// create pointer with all the buf value inside
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (dst = (char *)s2);
	if (!s2)
		return (dst = (char *)s1);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	while (s1[++i])
		dst[i] = s1[i];
	i = -1;
	while (s2[++i])
		dst[ft_strlen(s1) + i] = s2[i];
	dst[ft_strlen(s1) + i] = '\0';
	return (dst);
}

// keep somewhere what's after the '\n'
// Keep what's left
char	*keep_left(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (0);
	i = -1;
	while (s[++i] != '\n')
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

// Keep what's right
char	*keep_right(char *s)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	j = 0;
	while (s[i + j])
		j++;
	dst = malloc(j + 1);
	if (!dst)
		return (0);
	j = 1;
	while (s[i + j])
	{
		dst[i + j] = s[i + j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
