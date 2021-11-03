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

char	*get_texture(int i, char *str)
{
	char *text = NULL;

	i++;
	while (is_space(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
	{
		i += 2;
		text = ft_strdup(&str[i]);
	}
	return (text);
}

int	check_texture(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		while(is_space(str[i]))
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O')
			data->parsing.text_no = get_texture(i, str);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			data->parsing.text_so = get_texture(i, str);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			data->parsing.text_we = get_texture(i, str);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			data->parsing.text_ea = get_texture(i, str);
		else
			return (1);
	}
	return (0);
}

int	recup(char *file, t_data *data)
{
	int ret;
	int fd;
	char *recup;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		if(check_texture(recup, data) == 1 || check_map(data) == 1)
			return (1);
	}
	return (0);
}

/*

	Regarde autour d'une case '0' et vérifie qu'il n'y a pas de case vide sur les 8 cases qui l'entoure

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

int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	/*
	y = 0;
	while (data->map[0][y])
	{
		while (is_space(data->map[0][y]))
			y++;
		if (data->map[0][y] != '1')
			return (1);
		y++;
	}
*/
	while (data->map[x])
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
	return (0);
}

int	parsing(t_data *data)
{
	if (check_coordinate(data) || check_map(data))
		return (1);
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