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
			if (strchr("NSWE01 ", data->map[x][y]))
				y++;
			else
			{
				printf("NOT GOOD CHAR\t|%c|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
				return (1);
			}
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
				{
					printf("2 FOIS UNE COORDONNEE\t|%c|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	if (!c)
	{
		printf("PAS DE POSITION DE DEPART\n");
		return (1);
	}
	get_angle(data);
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

int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (data->map[0][y])
	{
		while (is_space(data->map[0][y]))
			y++;
		if (data->map[0][y] != '1')
			return (1);
		y++;
	}
	while (data->map[x] && x < data->map_heigth)
	{
		y = 0;
		while (data->map[x][y])
		{
			while (is_space(data->map[x][y]))
				y++;
			if (data->map[x][y] == '0')
			{
				if (check_surround(data, x, y))
				{
					printf("ERROR MAP |%c|\t|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	y = 0;
	while (data->map[x][y])
	{
		while (is_space(data->map[x][y]))
			y++;
		if (data->map[x][y] != '1')
		{
			printf("ERROR MAP |%c|\t|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
			return (1);
		}
		y++;
	}
	return (0);
}

