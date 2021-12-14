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

# include "get_next_line.h"
# include "libft.h"

# define BUFFER_SIZE 10
# define PI 3.14159265359
# define P2 (PI / 2)
# define P32 (3 * PI / 2)


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
	double HcoordX;
	double HcoordY;
	double VcoordX;
	double VcoordY;
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

typedef struct	s_threeD
{
	double	len;
	double	start;
	double	i;
	double	y_step;
	double	offset;
}				t_threeD;

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
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;
	char *text_s;
	int text_f;
	int text_c;
	int c;
	int	map_line;
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
	int			fd;
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
	char 		orientation;
	void		*mlx;
	void 		*mlx_win;
	char		**map;
	int			cellsize;
	int			win_width;
	int 		win_height;
	double 		length;
	double 		lengthx;
	double 		lengthy;
	int			userheight;
	int			r;
	int			g;
	int			b;
	int			t;
	int			map_height;
	int			map_width;
	char		player_cardinal;
	t_ray		ray;
	t_keys		key;
	t_text		text[4];
	t_parsing	parsing;
	t_threeD 	threeD;
}               t_data;

//ft_cub3D
int	make_image(t_data *data);

//ft_set
int set(t_data *data);
int set_key(t_data *data);
int	set_data(t_data *data);
int set_parsing(t_data *data);
int	set_ray(t_data *data);

//ft_error
int print_error(int errnum);
int print_error1(int errnum);

//ft_key
int	player_move(t_data *data, float angle, float l, int sign);
int	deal_key(t_data *data);
int close_window(t_data *data);
int	key_pressed(int keycode, t_data *data);
int	key_released(int keycode, t_data *data);

//ft_key_utils
int	define_step(t_data *data, float angle);

//ft_raycasting
int	define_step_x(t_data *data);
int	define_step_y(t_data *data);
int	raycasting_horizontal(t_data *data);
int	raycasting_vertical(t_data *data);
int	raycasting(t_data *data);

//ft_raycasting_utils
int	is_left(double angle);
int is_down(double angle);
int	define_lenghtf(t_data *data);

//ft_draw
int	draw_ceiling(t_data *data);
int	draw_wall(t_data *data, int side);
int	draw_floor(t_data *data);
int	define_coord_text(t_data *data, int side);
int draw_3d(t_data *data);

//ft_draw_utils
int draw_ray(t_data *data, int color);
int	get_orientation(t_data *data);
int	draw_minimap(t_data *data);

//ft_parsing
int	parsing(t_data *data, char *file);

//ft_parsing_map
int check_coordinate(t_data *data);
int	check_map(t_data *data);
int check_valid_char_map(t_data *data);
int	recup_map(t_data *data, char *file);

//ft_parsing_map_utils
int	check_wall(t_data *data);
int check_surround(t_data *data, int x, int y);
int	get_angle(t_data *data);

//ft_parsing_textures
int	parsing_text(char *str, t_data *data);
char	*get_path_text(int i, char *str);
int	recup(t_data *data);
int	check_text(t_data *data);
int	recup_text(t_data *data);

//ft_parsing_text_utils.c
int	ft_rgb_to_trgb(int t, int r, int g, int b);
int ato3i(char *str, int *a, int *b, int *c);
int get_img_text(t_data *data);
int	get_addr_text(t_data *data);

//ft_parsing_utils
int is_space(char str);
int	is_coordinate(char str);
void	fill_tab_zero(void *s, size_t n);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa(int nbr);

//ft_mlx_utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	big_pixel(t_data *data, int color, int i, int j, int l);

//ft_utils.c
double	check_overflow_angle(double angle);
int	print_textures(t_data *data);
int print_minimap(t_data *data);
int	print_outlines(t_data *data);
int	draw_ray_ex(t_data *data, int color, double angle);

#endif
