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

char	**ft_parsing(void)
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
