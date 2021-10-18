#include "cub3D.h"

int	set_data(t_data *data)
{
	data->px = 45;
	data->py = 35;
	data->angle = PI / 2;
	data->cellsize = 30;
	data->height = 1000;
	data->width = 2000;
	data->map = ft_recup_map();
	data->userheight = data->cellsize / 20;
	data->color_sky = 0x7a7a7a;
	data->color_ground = 0x00FF0000;
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