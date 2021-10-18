#include "cub3D.h"

/*int		is_correct(char *str)
{
	if (str == "NO" || str == "SO" || str == "WE" || str == "EA"
		|| str == "S" || str == "F" || str == "C")
		return (1);
	return (0);
}

char	ft_textures()
{
	if (is_correct(str))
}
*/

char	**ft_recup_map(void)
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

int		check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '0' || data->map[x][y] == '1')
				y++;
			else if (data->map[x][y] == 'N' || data->map[x][y] == 'S' || data->map[x][y] == 'E' || data->map[x][y] == 'W')
			{
				data->player_cardinal = data->map[x][y];
				y++;
			}
			else
				return (1);
		}
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