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
	double lengthf;
	int x;
	int y;
}				t_ray;

typedef struct	s_keys
{
	int w;
	int a;
	int s;
	int d;
	int l;
	int r;
	int e;
	int	stepX;
	int	stepY;
}				t_keys;

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

typedef struct	s_text
{
	void *img;
	int texx;
	int texy;
}				t_text;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bpp;
	int			line_length;
	int			end;
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
	int			userheight;
	t_ray		ray;
	t_keys		key;
	t_text		text;
}               t_data;


//ft_cub3D
int	make_image(t_data *img);
//ft_key
int	deal_key(t_data *img);
int	key_pressed(int keycode, t_data *img);
int	key_released(int keycode, t_data *img);
//ft_raycasting
int	raycasting(t_data *img);
//ft_draw
int draw_ray(t_data *img, int color);
int draw_3D(t_data *img, int color);
int	draw_minimap(t_data *img);
int print_minimap(t_data *img);
//parsing
char	**ft_parsing(void);
//ft_mlx_utils
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		big_pixel(t_data *img, int color, int i, int j, int l);
//ft_utils.c
double	check_overflow_angle(double angle);

//get_next_line
int	get_next_line(int fd, char **line);
//get_next_line_utils
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);


#endif
