/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:35 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/23 17:14:05 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static char	*keep_right(char *string)
{
	char	*dst;
	int		i;
	int		j;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != 10)
		i++;
	if (!string[i])
		return (free(string), NULL);
	dst = malloc(ft_strlen(string) - i + 1);
	if (!dst)
		return (free(string), NULL);
	j = 0;
	i++;
	while (string[i])
		dst[j++] = string[i++];
	dst[j] = 0;
	if (!dst[0])
		return (free(string), free(dst), NULL);
	return (free(string), dst);
}

static char	*read_save_string(int fd, char *string)
{
	char	*buff;
	char	*stash;
	int		rt;
	int		x;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rt = 1;
	x = 0;
	while (rt > 0 && !ft_strchr(string, 10))
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
			return (free(buff), NULL);
		if (rt == 0 && x == 0)
			return (free(buff), NULL);
		buff[rt] = 0;
		stash = string;
		string = ft_strjoin(stash, buff);
		free(stash);
		x++;
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*stash;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_save_string(fd, string);
	if (!string)
		return (NULL);
	stash = keep_left(string);
	string = keep_right(string);
	if (!stash)
		free(string);
	return (stash);
}
