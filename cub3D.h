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

# define BUFFER_SIZE 1000

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	float		px;
	float		py;
	int			dx;
	int			dy;
	float		angle;
	void		*mlx;
	void 		*mlx_win;
}               t_data;

typedef struct	s_parsing
{
	int res_x;
	int res_y;
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;
	char *text_s;
	char *text_f;
	char *text_c;
}				t_parsing;

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int	get_next_line(int fd, char **line);

char	**ft_parsing(void);


#endif
