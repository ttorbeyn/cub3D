#include "cub3D.h"

/*

	Vérifie qu'il y ait pas plusieurs fois une position de départ pour le joueur (N, S, E, W).
 	Attribue la position du joueur de base.
 	Change la lettre en un 0.

*/

int check_coordinate(t_data *data)
{
	int x;
	int y;
	int tab[256];

	x = 0;
	while (x < 256)
	{
		tab[x] = 0;
		x++;
	}
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (is_coordinate(data->map[x][y]))
			{
				if (tab[(int)data->map[x][y]] < 1)
				{
					data->px = x * data->cellsize;
					data->py = y * data->cellsize;
					data->orientation = data->map[x][y];
					tab[(int)data->map[x][y]]++;
					data->map[x][y] = '0';
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



/*

	Ouvre et récupere la map grace a un get_next_line

*/

char	**recup_map(void)
{
	int	fd;
	int	ret;
	char	*line;
	char	**map;
	int	x;

	fd = open("map2.cub", O_RDONLY);
	x = 0;
	map = malloc(sizeof(char *) * 100);
	while (1)
	{
		ret = get_next_line(fd, &line);
		map[x] = ft_strdup(line);
		free(line);
		x++;
		if (ret == 0)
		{
			map[x] = NULL;
			return (map);
		}
	}
}
