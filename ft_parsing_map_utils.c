#include "includes/cub3D.h"

/*

	Verifie autour d'une case qu'il n'y a pas
 	de case vide sur les 8 cases qui l'entoure.

*/

int	check_wall(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	while (x < data->map_height - 1)
	{
		y = 1;
		while (y < data->map_width - 1)
		{
			while (is_space(data->map[x][y]) && y < data->map_width - 1)
				y++;
			if (data->map[x][y] == '0' && check_surround(data, x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int check_surround(t_data *data, int x, int y)
{
	if (is_space(data->map[x - 1][y]) ||
		is_space(data->map[x][y - 1]) ||
		is_space(data->map[x + 1][y]) ||
		is_space(data->map[x][y + 1]) ||
		is_space(data->map[x - 1][y - 1]) ||
		is_space(data->map[x + 1][y + 1]) ||
		is_space(data->map[x - 1][y + 1]) ||
		is_space(data->map[x + 1][y - 1]))
		return (1);
	return (0);
}

int	get_angle(t_data *data)
{
	if (data->orientation == 'E')
		data->angle = PI / 2;
	if (data->orientation == 'O')
		data->angle = (3 * PI) / 2;
	if (data->orientation == 'N')
		data->angle = PI;
	if (data->orientation == 'S')
		data->angle = 0;
	return (0);
}
