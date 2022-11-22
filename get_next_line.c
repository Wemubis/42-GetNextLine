/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:35 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/22 15:40:34 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_separate(char *string, char *stash, char *left_over)
{
	stash = string;
	string = keep_left(stash);
	left_over = keep_right(stash);
	free(stash);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		buff[BUFFER_SIZE +1];
	char		*string;
	char		*stash;
	int			rt;

	string = NULL;
	rt = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	while (rt > 0)
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
			return (0);
		buff[rt] = 0;
		stash = string;
		string = ft_strjoin(stash, buff);
		free(stash);
		if (ft_strchr(string, '\n'))
			break ;
	}
	ft_separate(string, stash, left_over);
	return (string);
}
