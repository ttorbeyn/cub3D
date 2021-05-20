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

int	raycasting(t_data *img)
{
	double posX = img->px;
	double posY = img->py;
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	int x = 0;
	double cameraX;
	double raydirX;
	double raydirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	int stepX;
	int stepY;
	int hit = 0;
	int side;

	/*while (x < img->width)
	{*/

	cameraX = (2 * x) / (img->width - 1);
	//printf("%f\n", cameraX);
	raydirX = dirX + planeX * cameraX;
	//printf("%f\n", raydirX);
	raydirY = dirY + planeY * cameraX;
	mapX = (int)(posX);
	//printf("%d\n", mapX);
	mapY = (int)(posY);
	if (raydirX == 0)
		deltaDistX = 0;
	else
		deltaDistX = fabs(1.0 / raydirX);
	//printf("%f\n", deltaDistX);
	if (raydirY == 0)
		deltaDistY = 0;
	else
		deltaDistY = fabs(1.0 / raydirY);
	//printf("%f\n", deltaDistY);
	if (raydirX < 0)
	{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		printf("%d\n", mapX);
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	printf("%f\n", sideDistX);
	if (raydirY < 0)
	{
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
	printf("%f\n", sideDistY);
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (img->map[mapX][mapY] == 1)
			hit = 1;
	}
	printf ("hit:%d", hit);
		//x++;
	//}
	return (0);
}


int show_ray(t_data *img)
{
	int c;
	float x;
	float y;

	x = img->px;
	y = img->py;
	c = 0;
	while (c < 50)
	{
		my_mlx_pixel_put(img, x, y, 0x0000FF00);
		x += (cosf(img->angle));
		y -= (sinf(img->angle));
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
	raycasting(img);
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
	img.px = 22;
	img.py = 12;
	img.angle = 1;
	img.cellsize = 100;
	img.height = 1000;
	img.width = 2000;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_image(&img);
	mlx_hook(img.mlx_win, 2, 1L<<0, deal_key, &img);
	mlx_loop(img.mlx);
}