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

	Vérifie qu'il y ait pas plusieurs fois une position de départ pour
 	le joueur (N, S, E, W).
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

int check_outline(t_data *data)
{
	int x;
	int	y;
	int c;

	y = 0;
	c = 0;
	while (y < data->map_width)
	{
		if (!strchr(" 1", data->map[0][y])
				&& !strchr(" 1", data->map[data->map_heigth - 1][y]))
			return (print_error(9));
		if (strchr(" ", data->map[data->map_heigth - 1][y]))
			c++;
		y++;
	}
	x = 0;
	while (x <  data->map_heigth)
	{
		if (!strchr(" 1", data->map[x][0])
				&& !strchr(" 1", data->map[x][data->map_width - 1]))
			return (print_error(10));
		x++;
	}
	if (c >= data->map_width)
		return (print_error1(11));
	return (0);
}

int	check_map(t_data *data)
{
	if (check_valid_char_map(data))
		return (print_error(6));
	if (check_coordinate(data))
		return (1);
	if (check_outline(data))
		return (1);
	if (check_wall(data))
		return (print_error(9));
	get_angle(data);
	return (0);
}

int	recup_map(t_data *data, char *file)
{
	int	x;
	int y;
	int	ret;
	char	*recup;
	int len;

	x = 0;
	ret = 1;
	data->fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char*) * (data->map_heigth + 1));
	if (!data->map)
		return (1);
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
		len = ft_strlen(recup);
		data->map[x] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[x])
			return (1);
		y = 0;
		while (y < data->map_width)
		{
			if (y < len && (recup[y] == '0'
					|| is_coordinate(recup[y]) || recup[y] == '1'))
				data->map[x][y] = recup[y];
			else
				data->map[x][y] = ' ';
			y++;
		}
		data->map[x][y] = '\0';
		x++;
		free(recup);
	}
	data->map[x] = NULL;
	close(data->fd);
	return (0);
}
