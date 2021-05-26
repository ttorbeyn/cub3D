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

# define BUFFER_SIZE 10
# define PI 3.14159265359

# define PLAYER_FORWARD 13
# define PLAYER_BACK 1
# define PLAYER_LEFT 0
# define PLAYER_RIGHT 2
# define CAMERA_LEFT 123
# define CAMERA_RIGHT 124
# define ESC 53


typedef struct	s_ray
{
	double posX;  //position du joueur en x
	double posY;	//position du joueur en y
	int newPosX;
	int newPosY;
	double angle;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	int	stepX;
	int	stepY;
	double dx;
	double dy;
	double lengthx;
	double lengthy;
	double length;
	int x;
	int y;
}				t_ray;

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

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int			line_length;
	int			endian;
	double		px;
	double		py;
	int			dx;
	int			dy;
	float		angle;
	void		*mlx;
	void 		*mlx_win;
	char		**map;
	int			cellsize;
	int			width;
	int 		height;
	double 		length;
	double 		lengthx;
	double 		lengthy;
	t_ray		ray;
}               t_data;

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int	get_next_line(int fd, char **line);

char	**ft_parsing(void);


#endif
