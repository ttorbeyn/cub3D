#include "cub3D.h"

int get_coordinate(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (is_coordinate(data->map[x][y]))
			{
				data->px = x * data->cellsize;
				data->py = y * data->cellsize;
			}
			y++;
		}
		x++;
	}
	return (0);
}

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

char *get_texture(int i, char *str)
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

int check_texture(char *str, t_data *data)
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

int check_surround(t_data *data, int x, int y)
{
	if (is_space(data->map[x - 1][y]) ||
		is_space(data->map[x][y - 1]) ||
		is_space(data->map[x - 1][y - 1]) ||
		is_space(data->map[x + 1][y]) ||
		is_space(data->map[x][y + 1]) ||
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
	y = 0;
	while (data->map[0][y])
	{
		while (is_space(data->map[0][y]))
			y++;
		if (data->map[0][y] != '1')
			return (1);
		y++;
	}
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			while (is_space(data->map[x][y]))
				y++;
			if (is_coordinate(data->map[x][y]) || data->map[x][y] == '0')
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
/*
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			while (is_space(data->map[x][y]))
				y++;
			if (data->map[x][y] != '1')
			{
				printf("Pas de 1 au debut de la ligne %d\n", x);
				return (1);
			}
			if (data->map[x][y] == '0' || data->map[x][y] == '1')
				y++;
			if (is_coordinate(data->map[x][y]))
			{
				data->player_cardinal = data->map[x][y];
				data->px = x * data->cellsize;
				data->py = y * data->cellsize;
				y++;
			}
			if (data->map[x][y - 1] == '1' && is_space(data->map[x][y]))
			{
				while (is_space(data->map[x][y]))
					y++;
				if (data->map[x][y] != '1')
				{
					printf("CARACTERE INVALIDE 1 |%c|\t|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
					return (1);
				}
			}
			else if (data->map[x][y] != '0' && data->map[x][y] != '1' && !is_coordinate(data->map[x][y]))
			{
				printf("CARACTERE INVALIDE 2 |%c|\t|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
				return (1);
			}
			if (data->map[x][y] != '1')
			{
				printf("PAS DE 1 A LA FIN\n |%c|\t|\tPOS[%d][%d]\n", data->map[x][y], x + 1, y + 1);
				return (1);
			}
		}
	x++;
	}
	return (0);
*/
}

int	parsing(t_data *data)
{
	if (check_map(data) == 1)
		return (1);
	return (0);
}
