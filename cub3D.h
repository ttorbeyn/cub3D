#ifndef CUB3D_H
# define CUB3D_H


//open, close
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
//read, write
# include <unistd.h>
//printf, perror
# include <stdio.h>
//malloc, free, exit
# include <stdlib.h>
//strerror
# include <string.h>
# include <math.h>
# include <mlx.h>

# include <limits.h>

# define BUFFER_SIZE 2

size_t		ft_strlen(char *s);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);

#endif
