#include "includes/cub3D.h"

/*

	Vérifie que la map ne soit composée que de "01NSWE "

*/

int check_valid_char_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (strchr("01 NSWE", data->map[x][y]))
				y++;
			else
				return (1);
		}
	x++;
	}
	return (0);
}

/*

	Vérifie qu'il y ait pas plusieurs fois une position de départ pour le joueur (N, S, E, W).
 	Attribue la position du joueur de base.
 	Change la lettre en un 0.

*/

int check_coordinate(t_data *data)
{
	int x;
	int y;
	int c;

	x = 0;
	c = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (is_coordinate(data->map[x][y]))
			{
				if (c < 1)
				{
					data->px = x * data->cellsize + (data->cellsize / 2);
					data->py = y * data->cellsize + (data->cellsize / 2);
					data->orientation = data->map[x][y];
					data->map[x][y] = '0';
					c++;
				}
				else
					return (print_error(7));
			}
			y++;
		}
		x++;
	}
	if (!c)
		return (print_error(8));
	return (0);
}

/*

	Verifie autour d'une case qu'il n'y a pas
 	de case vide sur les 8 cases qui l'entoure

*/

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

/*

	Vérifie la map en 3 étapes :
 	- Verifie que la premiere ligne soit composée de 1 et d'espace uniquement
 	- Verifie le reste de la map en veillant a ce qu'un '0' n'ait
 	jamais un ' ' dans les 8 cases qui l'entoure
 	- Verifie que la derniere ligne soit composée de 1 et d'espace uniquement

*/

int check_outline(t_data *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->map_width)
	{
		if (!strchr(" 1", data->map[0][y]) && !strchr(" 1", data->map[data->map_heigth - 1][y]))
			return (1);
		y++;
	}
	x = 0;
	while (x <  data->map_heigth)
	{
		if (!strchr(" 1", data->map[x][0]) && !strchr(" 1", data->map[x][data->map_width]))
			return (1);
		x++;
	}
	return (0);
}

int	check_wall(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	while (x < data->map_heigth - 1)
	{
		y = 1;
		while (y < data->map_width - 1)
		{
			while (is_space(data->map[x][y]))
				y++;
			if (data->map[x][y] == '0' && check_surround(data, x, y))
					return (print_error(9));
			y++;
		}
		x++;
	}
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

int	check_map(t_data *data)
{
	if (check_valid_char_map(data))
		return (print_error(6));
	if (check_coordinate(data))
		return (1);
	if (check_outline(data))
		return (print_error(9));
	if (check_wall(data))
		return (1);
	get_angle(data);
	return (0);
}

int	recup_map(t_data *data, char *file)
{
	int	x;
	int	ret;
	char	*recup;

	x = 0;
	ret = 1;
	data->fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char*) * (data->map_heigth + 1));
	while (x < data->parsing.map_line)
	{
		get_next_line(data->fd, &recup);
		x++;
		free(recup);
	}
	x = 0;
	while (ret == 1)
	{
		ret = get_next_line(data->fd, &recup);
		data->map[x++] = ft_strdup(recup);
		free(recup);
		if (ret == 0)
			break;
	}
	data->map[x] = NULL;
	close(data->fd);
	return (0);
}
