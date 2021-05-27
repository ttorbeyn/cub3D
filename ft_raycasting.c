#include "cub3D.h"
#include <stdio.h>

int set_ray(t_data *img)
{
	img->ray.posX = img->px / img->cellsize;  //position du joueur en x
	img->ray.posY = img->py / img->cellsize;	//position du joueur en y
	img->ray.mapX = (int)(img->ray.posX); //case dans laquelle joueur se trouve en x
	img->ray.mapY = (int)(img->ray.posY); //case dans laquelle joueur se trouve en y
	img->ray.dx = 0;
	img->ray.dy = 0;
	img->ray.sideDistX = 0;
	img->ray.sideDistY = 0;
	img->ray.deltaDistX = 0;
	img->ray.deltaDistY = 0;
	img->ray.lengthx = 0;
	img->ray.lengthy = 0;
	img->ray.length = 0;
	return (0);
}

int	raycasting_vertical(t_data *img)
{
	int c = 0;
	int x;

	if ((img->ray.angle >= PI/2 && img->ray.angle <= ((3 * PI) / 2)))
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
		if ((img->ray.angle > PI/2 && img->ray.angle < ((3 * PI) / 2)))
			x = (int)img->ray.sideDistX - 1;
		if (img->map[x][(int)img->ray.sideDistY] != '1')
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
		y = (int)img->ray.sideDistY;
		if ((img->ray.angle > PI && img->ray.angle < (2 * PI)))
			y = (int)img->ray.sideDistY - 1;
		if (img->map[(int)img->ray.sideDistX][y] != '1')
		{
			if (img->ray.angle != PI/2 && img->ray.angle != 3*PI/2 && tanf(img->ray.angle) != 0)
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

int	raycasting(t_data *img)
{
	img->ray.angle = img->angle - (PI/6);
	if (img->ray.angle > (2 * PI))
		img->ray.angle -= (2 * PI);
	if (img->ray.angle < 0)
		img->ray.angle += (2 * PI);
	int x = 0;
	img->ray.x = 0;
	float angle;

	while (x < img->width)
	{
		set_ray(img);
		raycasting_vertical(img);
		raycasting_horizontal(img);
		int color;

		color = 0x00696969;
		img->ray.length = img->ray.lengthx;
		if (img->ray.lengthx > img->ray.lengthy)
		{
			img->ray.length = img->ray.lengthy;
			color = 0x00808080;
		}
		angle= img->angle - img->ray.angle;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)
			angle += (2 * PI);
		img->ray.lengthf = img->ray.length * cosf(angle);
		draw_3D(img, color);
		draw_ray(img, 0x0000FF00);
		img->ray.angle += (PI/3) / (img->width);
		if (img->ray.angle > (2 * PI))
			img->ray.angle -= (2 * PI);
		if (img->ray.angle < 0)
			img->ray.angle += (2 * PI);
		x++;
	}
	img->ray.angle = img->angle;
	raycasting_vertical(img);
	raycasting_horizontal(img);
	img->ray.length = img->ray.lengthx;
	if (img->ray.lengthx > img->ray.lengthy)
		img->ray.length = img->ray.lengthy;
	draw_ray(img, 0xFF0000);
	return (0);
}








