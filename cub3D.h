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
	double posX;  	//position du joueur en x
	double posY;	//position du joueur en y
	double angle; 	//direction du joueur en radian
	int mapX;
	int mapY;
	double HsideDistX;
	double HsideDistY;
	double VsideDistX;
	double VsideDistY;
	double deltaDistX;
	double deltaDistY;
	int	stepX;
	int	stepY;
	double dx;
	double dy;
	double lengthV;
	double lengthH;
	double length;
	double lengthf;
	double x;
	double y;
	int side;
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
	void 	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		end;
	double 	texx;
	double 	texy;
	int		texpos;
	int		width;
	int		height;
	unsigned int	*color;
}				t_text;

typedef struct  s_data {
	void		*img;
	int			*addr;
	int			bpp;
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
	int			color_sky;
	int			color_ground;
	int			map_heigth;
	int			map_width;
	char		player_cardinal;
	t_ray		ray;
	t_keys		key;
	t_text		text;
}               t_data;


//ft_cub3D
int	make_image(t_data *data);
//ft_set
int set_key(t_data *data);
int	set_data(t_data *data);
//ft_key
int	deal_key(t_data *data);
int close_window(t_data *data);
int	key_pressed(int keycode, t_data *data);
int	key_released(int keycode, t_data *data);
//ft_raycasting
int	raycasting(t_data *data);
//ft_draw
int draw_ray(t_data *data, int color);
int draw_3D(t_data *data);
int	draw_text(t_data *data);
int	draw_minimap(t_data *data);
int print_minimap(t_data *data);
//parsing
char	**ft_recup_map(void);
int		check_map(t_data *data);
int		parsing(t_data *data);
//ft_mlx_utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		big_pixel(t_data *data, int color, int i, int j, int l);
//ft_utils.c
double	check_overflow_angle(double angle);
//get_next_line
int	get_next_line(int fd, char **line);
//get_next_line_utils
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);


#endif
