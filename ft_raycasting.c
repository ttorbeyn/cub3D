#include "cub3D.h"
#include <stdio.h>

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

	l = img->cellsize / 20;
	i = img->px - (l / 2);
	j = img->py + (l / 2);
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

int show_ray(t_data *img, int color)
{
	double c;
	double x;
	double y;

	x = img->px;
	y = img->py;
	c = 0;
	while (c <= (img->ray.length * img->cellsize) && c < 800 &&
		   x > 0 && y > 0 && x < img->width && y < img->height)
	{
		my_mlx_pixel_put(img, x, y, color);
		x += (cosf(img->ray.angle));
		y += (sinf(img->ray.angle));
		c += 1;
	}
	return (0);
}

int	raycasting_vertical(t_data *img)
{
	int c = 0;
	int x;
	int y;

	if ((img->ray.angle > PI/2 && img->ray.angle < ((3 * PI) / 2)))
	{
		img->ray.stepX = -1;
		img->ray.dx = img->ray.posX - img->ray.mapX;
	}
	else if ((img->ray.angle < PI/2) || (img->ray.angle > ((3 * PI) / 2)))
	{
		img->ray.stepX = 1;
		img->ray.dx = 1.0 - (img->ray.posX - img->ray.mapX);
	}
	img->ray.sideDistX = img->ray.posX + img->ray.dx * img->ray.stepX;
	if (!(img->ray.angle == PI/2 || img->ray.angle == 3*PI/2))
		img->ray.sideDistY = img->ray.posY + (tanf(img->ray.angle) * img->ray.dx * img->ray.stepX);
	while (c < 7 && img->ray.sideDistX >= 0 && img->ray.sideDistY >= 0 &&
			img->ray.sideDistX <= 8 && img->ray.sideDistY <= 8)
	{
		x = (int)img->ray.sideDistX;
		y = (int)img->ray.sideDistY;
		if ((img->ray.angle > PI/2 && img->ray.angle < ((3 * PI) / 2)))
			x = (int)img->ray.sideDistX - 1;
		if (img->map[x][y] != '1')
		{
			img->ray.sideDistX += img->ray.stepX;
			if (!(img->ray.angle == PI/2 || img->ray.angle == 3*PI/2))
				img->ray.sideDistY += tanf(img->ray.angle) * img->ray.stepX;
			c++;
		}
		else
			c = 7;
	}
	img->ray.deltaDistX = img->ray.sideDistX - img->ray.posX;
	img->ray.deltaDistY = img->ray.sideDistY - img->ray.posY;
	img->ray.lengthx = hypot(img->ray.deltaDistX, img->ray.deltaDistY);
	return (0);
}

int	raycasting_horizontal(t_data *img)
{
	int c = 0;
	int x;
	int y;

	if ((img->ray.angle > 0 && img->ray.angle < PI))
	{
		img->ray.stepY = 1;
		img->ray.dy = 1.0 - (img->ray.posY - img->ray.mapY);
	}
	else if ((img->ray.angle > PI && img->ray.angle < (2 * PI)))
	{
		img->ray.stepY = -1;
		img->ray.dy = img->ray.posY - img->ray.mapY;
	}

	if (!(img->ray.angle == PI/2 || img->ray.angle == 3*PI/2) && tanf(img->ray.angle) != 0)
		img->ray.sideDistX = img->ray.posX + ((img->ray.dy * img->ray.stepY) / tanf(img->ray.angle));
	img->ray.sideDistY = img->ray.posY + (img->ray.dy * img->ray.stepY);
	while (c < 7 && img->ray.sideDistX >= 0 && img->ray.sideDistY >= 0 &&
			img->ray.sideDistX <= 8 && img->ray.sideDistY <= 8)
	{
		x = (int)img->ray.sideDistX;
		y = (int)img->ray.sideDistY;
		if ((img->ray.angle > PI && img->ray.angle < (2 * PI)))
			y = (int)img->ray.sideDistY - 1;
		if (img->map[x][y] != '1')
		{
			if (!(img->ray.angle == PI/2 || img->ray.angle == 3*PI/2) && tanf(img->ray.angle) != 0)
				img->ray.sideDistX += img->ray.stepY / tanf(img->ray.angle);
			img->ray.sideDistY += img->ray.stepY;
			c++;
		}
		else
			c = 7;
	}
	img->ray.deltaDistX = img->ray.sideDistX - img->ray.posX;
	img->ray.deltaDistY = img->ray.sideDistY - img->ray.posY;
	img->ray.lengthy = hypot(img->ray.deltaDistX, img->ray.deltaDistY);
	return (0);
}

int print_3D(t_data *img)
{
	double len = img->height / img->ray.length;
	if (len >= img->height)
		len = img->height;
	img->ray.y = (img->height / 2) - (len / 2);


	while (len > 0)
	{
		my_mlx_pixel_put(img, img->ray.x, img->ray.y, 0x007F7F7F);
		len--;
		img->ray.y++;
	}
	img->ray.x++;
	return (0);
}


int	raycasting(t_data *img)
{
	img->ray.posX = img->px / img->cellsize;  //position du joueur en x
	img->ray.posY = img->py / img->cellsize;	//position du joueur en y
	img->ray.angle = img->angle; //angle du rayon
	img->ray.mapX = (int)(img->ray.posX); //case dans laquelle joueur se trouve en x
	img->ray.mapY = (int)(img->ray.posY);	//case dans laquelle joueur se trouve en y
	img->ray.dx = 0;
	img->ray.dy = 0;
	img->ray.x = 0;
	img->ray.angle = img->angle - (PI / 3);
	int x = 0;

	while (x < img->width)
	{
		raycasting_vertical(img);
		raycasting_horizontal(img);
		img->ray.length = img->ray.lengthx;
		if (img->ray.lengthx > img->ray.lengthy)
			img->ray.length = img->ray.lengthy;
		img->ray.angle += (PI / 3) / (img->width / 2);
		print_3D(img);
		show_ray(img, 0x0000FF00);
		x++;
	}
	img->ray.angle = img->angle;
	raycasting_vertical(img);
	raycasting_horizontal(img);
	img->ray.length = img->ray.lengthx;
	if (img->ray.lengthx > img->ray.lengthy)
		img->ray.length = img->ray.lengthy;
	show_ray(img, 0xFF0000);
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

int print_map(t_data *img)
{
	int x;
	int y;

	x = 0;
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			printf("%c", img->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}

int	minimap(t_data *img)
{
	int	x;
	int y;

	x = 0;
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			if (img->map[x][y] == '1')
				big_pixel_map(img, 0x000000FF, (x + 1), (y + 1));
			else
				big_pixel_map(img, 0x007F7F7F, (x + 1), (y + 1));
			y++;
		}
		x++;
	}
	return (0);
}

int	make_image(t_data *img)
{
	minimap(img);
	raycasting(img);

	big_pixel_user(img, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	deal_key(int keycode, t_data *img)
{
	int l;

	l = img->cellsize / 10;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	if (keycode == PLAYER_FORWARD)
	{
		img->px += l * cosf(img->angle);
		img->py += l * sinf(img->angle);
	}
	if (keycode == PLAYER_BACK)
	{
		img->px -= l * cosf(img->angle);
		img->py -= l * sinf(img->angle);
	}
	if (keycode == PLAYER_LEFT)
	{
		img->px -= l * cosf(img->angle + (PI / 2));
		img->py -= l * sinf(img->angle + (PI / 2));
	}
	if (keycode == PLAYER_RIGHT)
	{
		img->px += l * cosf(img->angle + (PI / 2));
		img->py += l * sinf(img->angle + (PI / 2));
	}
	if (keycode == CAMERA_RIGHT)
		img->angle += 0.1;
	if (keycode == CAMERA_LEFT)
		img->angle -= 0.1;
	if (img->angle > (2 * PI))
		img->angle -= (2 * PI);
	if (img->angle < 0)
		img->angle += (2 * PI);
	if (keycode == ESC)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	make_image(img);
	return (0);
}



int	main(void)
{
	t_data	img;
	img.px = 45;
	img.py = 35;
	img.angle = PI/2;
	img.cellsize = 10;
	img.height = 1000;
	img.width = 2000;
	img.map = ft_parsing();


	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_image(&img);
	mlx_hook(img.mlx_win, 2, 1L<<0, deal_key, &img);
	mlx_loop(img.mlx);
}