#include "includes/cub3D.h"

int	set_data(t_data *data)
{
	data->cellsize = 20;
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
	data->parsing.c = 1;
	data->parsing.map_line = 0;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
	data->parsing.text_ea = NULL;
	data->parsing.text_we = NULL;
	data->parsing.text_c = -1;
	data->parsing.text_f = -1;
	return (0);
}

int set(t_data *data)
{
	set_data(data);
	set_key(data);
	set_parsing(data);
	return (0);
}