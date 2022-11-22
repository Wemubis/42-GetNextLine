/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:40 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:52 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*------------INCLUD------------*/
# include <stdlib.h>

/*------------PROTOS------------*/
/*-----HEAD-----*/
char		*get_next_line(int fd);
static void	*ft_separate(char *string, char *stash, char *left_over);

/*-----HELP-----*/
size_t		ft_strlen(char *str);
int			*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*keep_left(const char *str);
char		*keep_right(const char *str);

/*------------STRUCT------------*/

#endif