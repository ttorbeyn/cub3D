#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int			px;
	int			py;
	void		*mlx;
	void 		*mlx_win;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int 	big_pixel(t_data *img)
{
	int x;
	int y;
	int l;

	printf("px:%d\n", img->px);
	printf("py:%d\n", img->py);
	l = 10;
	x = 0;
	while (x < l)
	{
		img->py -= l;
		y = 0;
		while (y < l)
		{
			my_mlx_pixel_put(img, img->px, img->py, 0x00FF0000);
			img->py++;
			y++;
		}
		img->px++;
		x++;
	}
	img->px -= l;
	//img->py -= 5;
	return (0);
}
/*
int	render_next_frame(t_data *img)
{
	int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);


	while (img->px < 100 || img->py < 100)
	{
		img->px++;
		img->py++;
	}

	big_pixel(img);
	return (0);
}
*/
int	deal_key(int key, t_data *img)
{
	int l;

	l = 10;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, 2000, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (key == 0)
		img->px -= l;
	if (key == 2)
		img->px += l;
	if (key == 1)
		img->py += l;
	if (key == 13)
		img->py -= l;

	big_pixel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	//printf("%d\n", img->px);
	return (0);
}
/*
int ft_refresh(t_data *img)
{
	big_pixel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
*/
int	main(void)
{
	t_data	img;
	img.px = 1000;
	img.py = 500;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2000, 1000, "cub3D");
	img.img = mlx_new_image(img.mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	big_pixel(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, deal_key, &img);
//	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
}