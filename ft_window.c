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
	int i;
	int j;
	int l;

	i = img->px - 2;
	j = img->py + 2;
	l = 5;
	x = 0;
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

/*
float	dist(t_data img, float px, float py)
{

}
*/
float calculate_ray(t_data *img)
{
	float	x;
	float	y;
	float	dx;
	/*float	dy;
	int	stepx;
	int	stepy;
	int xstep;
	int ystep;
	float	xintercept;
	float	yintercept;*/
	float dist;


	dx = img->cellsize - ((img->px / img->cellsize) - (int)(img->px / img->cellsize));
	printf("dx:%f\n", dx);
	//dy = 1 - (img->py - (int)img->py);
	x = img->px + dx;
	y =	img->py + (tanf(img->angle) * dx);
	dist = dx / sinf(img->angle);
	while (img->map[(int)x][(int)y] != 1)
	{
		x += 1;
		y += tanf(img->angle);
		dist += (1 / sinf(img->angle));
	}
	//dist = ft_dist(img, x, y);
	return (dist);
}


int show_ray(t_data *img)
{
	int c;
	float x;
	float y;
	float l;
	float	dist;

	x = img->px;
	y = img->py;
	c = 0;
	l = x;
/*
	l = 0;
	while (img->map[x][y] == '0')
	{
		l += sqrtf(pow(cosf(img->angle), 2) + pow(sinf(img->angle), 2));
	}
	//l = l * 100;

	printf("%f\n", l);
	l -= (int)l;
	printf("%f\n", l);
*/
	dist = calculate_ray(img);
	while (c < 50)
	{
		my_mlx_pixel_put(img, x, y, 0x0000FF00);

		x += (cosf(img->angle));
		//printf("px:%f\n", img->px);
		y -= (sinf(img->angle));
		//printf("py:%f\n", img->py);

		c++;
	}
	return (0);
}

int	big_pixel_map(t_data *img, int color, int i, int j)
{
	int x;
	int y;
	int l;

	i *= img->cellsize;
	j *= img->cellsize;
	l = img->cellsize - 1;
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
	int	x;
	int y;

	x = 0;
	img->map = ft_parsing();
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			if (img->map[x][y] == '1')
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
	show_ray(img);
	big_pixel_user(img, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	deal_key(int keycode, t_data *img)
{
	int l;

	l = 10;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, 2000, 1000);
	if (keycode == 0)
		img->px -= l;
	if (keycode == 2)
		img->px += l;
	if (keycode == 13)
	{
		img->py -= l * sinf(img->angle);
		img->px += l * cosf(img->angle);
	}
	if (keycode == 1)
	{
		img->py += l * sinf(img->angle);
		img->px -= l * cosf(img->angle);
	}
	if (keycode == 123)
		img->angle += 0.1;
	if (keycode == 124)
		img->angle -= 0.1;
	if (img->angle > 6.28)
		img->angle -= 6.28;
	if (img->angle < 0)
		img->angle += 6.28;
	printf("ang:%f\n", img->angle);
	printf("px:%f\n", img->px);
	printf("py:%f\n", img->py);
	if (keycode == 53)
		mlx_destroy_window(img->mlx, img->mlx_win);
	make_image(img);
	return (0);
}

int	main(void)
{
	t_data	img;
	img.px = 100;
	img.py = 50;
	img.angle = 1;
	img.cellsize = 100;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2000, 1000, "cub3D");
	img.img = mlx_new_image(img.mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_image(&img);
	mlx_hook(img.mlx_win, 2, 1L<<0, deal_key, &img);
	mlx_loop(img.mlx);
}