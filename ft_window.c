#include <mlx.h>
#include <stdio.h>
#include "cub3D.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	big_pixel_user(t_data *img, int color)
{
	int x;
	int y;
	int l;

	printf("px:%d\n", img->px);
	printf("py:%d\n", img->py);
	l = 6;
	x = 0;
	while (x < l)
	{
		img->py -= l;
		y = 0;
		while (y < l)
		{
			my_mlx_pixel_put(img, img->px, img->py, color);
			img->py++;
			y++;
		}
		img->px++;
		x++;
	}
	img->px -= l;
	return (0);
}

int show_ray(t_data *img)
{
	int c;
	float x;
	float y;

	x = (float)img->px;
	y = (float)img->py;
	c = 0;
	while (c < 50)
	{
		my_mlx_pixel_put(img, x, y, 0x0000FF00);
		x += (cosf(img->angle));
		y += (sinf(img->angle));
		c++;
	}
	return (0);
}

int	big_pixel_map(t_data *img, int color, int i, int j)
{
	int x;
	int y;
	int l;

	i *= 100;
	j *= 100;
	l = 99;
	x = 0;
	i -= l;
	while (x < l)
	{
		j -= l;
		y = 0;
		while (y < l)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (0);
}

int	minimap(t_data *img)
{
	char **map;
	int	x;
	int y;

	x = 0;
	map = ft_parsing();
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				big_pixel_map(img, 0x000000FF, (y + 1), (x + 1));
			else
				big_pixel_map(img, 0x007F7F7F, (y + 1), (x + 1));
			y++;
		}
		x++;
	}
	return (0);
}

int	make_image(t_data *img)
{
	minimap(img);
	big_pixel_user(img, 0x00FF0000);
	show_ray(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	deal_key(int keycode, t_data *img)
{
	int l;

	l = 5;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, 2000, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	printf("%d\n", keycode);
	if (keycode == 0)
		img->px -= l;
	if (keycode == 2)
		img->px += l;
	if (keycode == 1)
		img->py += l;
	if (keycode == 13)
		img->py -= l;
	if (keycode == 123)
		img->angle += 0.1;

	if (keycode == 124)
		img->angle -= 0.1;
	if (keycode == 53)
		mlx_destroy_window(img->mlx, img->mlx_win);
	printf("%f\n", img->angle);
	make_image(img);
	return (0);
}

int	main(void)
{
	t_data	img;
	img.px = 200;
	img.py = 200;
	img.angle = 1;


	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2000, 1000, "cub3D");
	img.img = mlx_new_image(img.mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	make_image(&img);
	mlx_hook(img.mlx_win, 2, 1L<<0, deal_key, &img);
	mlx_loop(img.mlx);
}