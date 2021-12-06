#include "includes/cub3D.h"

int	set_data(t_data *data)
{
	data->map_heigth = 13;
	data->map_width = 32;
	data->cellsize = 30;
	data->height = 1000;
	data->width = 2000;
	data->userheight = data->cellsize / 20;
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

int set_parsing(t_data *data)
{
	data->parsing.c = 0;
	return (0);
}