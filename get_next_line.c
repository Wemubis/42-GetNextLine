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
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*string;
	char		*stash;
	int			rt;

	string = NULL;
	if (BUFFER_SIZE <= 0)
		return (0);
	rt = BUFFER_SIZE;
	while (rt > 0)
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
			return (0);
		buff[rt] = 0;
		stash = string;
		string = ft_strjoin(stash, buff);
		stash = NULL;
		if (ft_strchr(string, 10))
			break ;
	}
	stash = keep_left(string);
	string = ft_strchr(buff, 10);
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
