#include <mlx.h>
#include <math.h>
#include "../cub3D.h"

# define

int show_ray(t_data *img)
{
	float	aTan = -1 / tanf(img->angle);
	float ry;
	float rx;
	float xo;
	float yo;
	int dof;
	int mx;
	int my;
	int mp;

	dof = 0;
	if (img->angle > 3.14) //looking down
	{
		ry = (((int)img->py*6)/6)-0.0001;
		rx = (img->py - ry) * aTan + img->px;
		yo = -100;
		xo = -yo * aTan;
	}
	if (img->angle < 3.14) //looking down
	{
		ry = (((int)img->py*6)/6)+100;
		rx = (img->py - ry) * aTan + img->px;
		yo = 100;
		xo = -yo * aTan;
	}
	if (img->angle == 3.14 || img->angle == 0)
	{
		rx = img->px;
		ry = img->py;
		dof = 8;
	}
	while (dof < 8)
	{
		mx = (int)(rx)*6;
		my = (int)(ry)*6;
		mp = my *
	}

}

float calculate_ray(t_data *img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int	stepx;
	int	stepy;
	int xstep;
	int ystep;
	float	xintercept;
	float	yintercept;
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

int	raycasting(t_data *img)
{
	double posX = img->px / img->cellsize;  //position du joueur en x
	double posY = img->py / img->cellsize;	//position du joueur en y
	double angle = img->angle; //angle du rayon
	int mapX = (int)(posX); //case dans laquelle joueur se trouve en x
	//int mapY = (int)(posY);	//case dans laquelle joueur se trouve en y
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double pi = 3.14159265359;
	//int stepX;
	//int stepY;
	//double length;
	float dx;


	if (angle > 0 && angle < pi/2)
	{
		//stepX = 1;
		//stepY = 1;
		printf("posX:%f\n", posX);
		printf("posY:%f\n", posY);
		printf("mapX:%d\n", mapX);
		dx = 1.0 - (posX - mapX);
		printf("dx:%f\n", dx);
		sideDistX = posX + dx;
		printf("sx:%f\n", sideDistX);
		sideDistY = posY + (tanf(angle) * dx);
		printf("sy:%f\n", sideDistY);
		deltaDistX = sideDistX - posX;
		deltaDistY = sideDistY - posY;
		img->length = sqrtf((deltaDistX * deltaDistX) + (deltaDistY * deltaDistY));
	}
	else
		img->length = 1.0;
	printf("l:%f\n", img->length);
	return (0);
}

/*
int	raycasting(t_data *img)
{
	double posX = img->px;  //position du joueur en x
	double posY = img->py;	//position du joueur en y
	double dirX = -1;	//direction de la camera en x
	double dirY = 0;	//direction de la camera en x
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

	while (x < img->width)
	{

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
*/

/*
int textures[]=               //all 32x32 textures
		{
				//Checkerboard
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		};
*/

/*
int color_textures(int i)
{
	int c;

	c = 0xff0000;
	if (i == 1)
		c = 0xffd700;
	return (c);
}
*/

int	print_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			printf("%c", data->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}