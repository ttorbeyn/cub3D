#include <mlx.h>
#include <math.h>
#include "../cub3D.h"

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
*/