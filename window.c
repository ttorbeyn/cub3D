#include <mlx.h>
#include <math.h>
#include "cub3D.h"

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

void			my_mlx_line_put(int h, int a, int b, t_data *img, int color)
{
	int c;

	c = (h / 2) - (b / 2);
	while (b)
	{
		my_mlx_pixel_put(img, a, c, color);
		c++;
		b--;
	}

}

/*
void	ft_buttons(unsigned char key, int x, int y)
{
	if (key == 'a')
		px -= 5;
	if (key == 'a')
		px -= 5;
	if (key == 'a')
		px -= 5;
	if (key == 'a')
		px -= 5;
}
*/

int 	big_pixel(t_data *img)
{
	int x;

	printf("bp:%d\n", img->py);
	x = img->py + 5;
	while (img->px < x)
	{
		img->py = x - 5;
		while (img->py < x)
		{
			my_mlx_pixel_put(img, img->px, img->py, 0x00FF0000);
			img->py++;
		}
		img->px++;
	}
	return (0);
}

int	deal_key(int key, t_data *img)
{
	if (key == 0)
	{
		img->px += 5;
	}
	printf("%d\n", img->px);
	return (0);
}

int ft_refresh(t_data *img)
{
	mlx_key_hook(img->mlx_win, deal_key, img);
	big_pixel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	ft_close(int key, t_data *img)
{
	if (key == 53)
		mlx_destroy_window(img->mlx, img->mlx_win);
	return (0);
}

int             main(void)
{
	t_data  img;
	/*int		a;
	int		b;
	int i;
	img.px = 300;
	img.py = 300;
	int x;
	*/

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2000, 1000, "cub3D");
	img.img = mlx_new_image(img.mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*x = 1000;
	a = 0;
	while (a < 500)
	{
		b = 1000;
		while (b < x)
		{
			my_mlx_pixel_put(&img, a, b, 0x00FF0000);
			b++;
		}
		a++;
		x--;
	}
	a = 0;
	b = 200;
	i = 0;
	while (i < 2000 && b < 1000 && a < 1000)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF0000);
		b++;
		a++;
		i++;
	}*/
	/*a = 800;
	b = 1000;
	i = 0;
	while (i < 2000 && b > 0 && a < 1500)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF7F7F);
		b--;
		a++;
		i++;
	}
	a = 1500;
	b = 300;
	i = 0;
	while (i < 2000 && b < 1000 && a < 2000)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF0000);
		b++;
		a++;
		i++;
	}*/

	mlx_loop_hook(img.mlx, ft_refresh, &img);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_close, &img);
	mlx_loop(img.mlx);
}