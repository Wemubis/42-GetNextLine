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

#include <stdio.h>
#include <fcntl.h>

char	*keep_right(char *string)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != 10)
		i++;
	if (!string[i])
		return (0);
	dst = malloc(sizeof(char) * (ft_strlen(string) - i + 1));
	if (!dst)
		return (0);
	j = 0;
	while (string[i])
		dst[j++] = string[i++];
	dst[j] = 0;
	return (dst);
}

char	*read_save_string(int fd, char *string)
{
	char	*buff;
	char	*stash;
	int		rt;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	rt = 1;
	while (rt > 0 && !ft_strchr(string, 10))
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
		{
			free(buff);
			return (0);
		}
		buff[rt] = 0;
		stash = string;
		string = ft_strjoin(stash, buff);
		stash = NULL;
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{

	static char	*string;
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = string;
	string = read_save_string(fd, stash);
	if (!string)
	{
		string = NULL;
		return (0);
	}
	stash = keep_left(string);
	string = keep_right(string);
	return (stash);
}

/*----------------------MAIN-----------------------*/

int	main(void)
{
	int		fd;
	char	*remit;

	fd = open("cucu", O_RDONLY);
	remit = get_next_line(fd);
	printf("\npart 1 : %s", remit);
	remit = get_next_line(fd);
	printf("\npart 2 : %s", remit);
	remit = get_next_line(fd);
	printf("\npart 3 : %s", remit);
	remit = get_next_line(fd);
	printf("\npart 4 : %s", remit);
	close(fd);
	return (0);
}
