#include "cub3D.h"

int		is_coordinate(char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (1);
	return (0);
}
/*
char	ft_textures()
{
	if (is_correct(str))
}
*/

static	int is_space(char str)
{
	int	i;

	i = 0;
	while (str == ' ' || str == '\t' || str == '\n' || str == '\v'
		   || str == '\f' || str == '\r')
		i++;
	return (i);
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

int get_texture(char *text, t_data *data, int i)
{
	i++;
	while (is_space(str[i]))
		i++;

}

int check_texture(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O')
			get_texture(data->parsing.text_no, data, i);
		else if (str[i] == 'S' && str[i + 1] == 'O', i)
			get_texture(data->parsing.text_so, data);
		else if (str[i] == 'W' && str[i + 1] == 'E', i)
			get_texture(data->parsing.text_we, data);
		else if (str[i] == 'E' && str[i + 1] == 'A', i)
			get_texture(data->parsing.text_ea, data);
		else
			return (1);
	}
	return (0);
}

int		recup(char *file, t_data *data)
{
	int ret;
	int fd;
	char *recup;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		if(check_texture(recup, data) == 1 || check_map(recup, data) == 1)
			return (1);
	}

}

int		check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		if (data->map[x][y] != '1')
			return (1);
		while (data->map[x][y])
		{
			if (data->map[x][y] == '0' || data->map[x][y] == '1')
				y++;
			else if (is_coordinate(data->map[x][y]))
			{
				data->player_cardinal = data->map[x][y];
				data->px = x * data->cellsize;
				data->py = y * data->cellsize;
				y++;
			}
			else
				return (1);
		}
		if (data->map[x][--y] != '1')
			return (1);
		x++;
	}
	return (0);
}

int		parsing(t_data *data)
{
	if (check_map(data) == 1)
		return (1);
	return (0);
}