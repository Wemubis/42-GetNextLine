/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:31 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/23 16:57:36 by mle-boud         ###   ########.fr       */
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

char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// check if "\n" + Keep what's right
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

// create pointer with all the buf value inside
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = -1;
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
		return (NULL);
	while (s[i] != 10 && s[i])
		i++;
	dst = malloc(sizeof(char) * (i + 2));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i] != 10 && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	if (s[i] == 10)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
