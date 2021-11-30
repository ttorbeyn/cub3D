#include "includes/cub3D.h"

int	set_data(t_data *data)
{
	data->map_heigth = 13;
	data->map_width = 32;
	data->angle = PI / 2;
	data->cellsize = 30;
	data->height = 1000;
	data->width = 2000;
	data->userheight = data->cellsize / 20;
	data->color_sky = 3016396;
	data->color_ground = data->parsing.text_f;
	return (0);
}

int set_key(t_data *data)
{
	data->key.w = 0;
	data->key.a = 0;
	data->key.s = 0;
	data->key.d = 0;
	data->key.l = 0;
	data->key.r = 0;
	data->key.e = 0;
	return (0);
}