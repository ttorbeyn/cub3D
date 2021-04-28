/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:00:54 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/19 16:00:57 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t		ft_strlen(char *s);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);

#endif
