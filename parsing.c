#include "cub3D.h"

//char	**map(char *line)
//{

//}


int	main(void)
{
	int		fd;
	int		ret;
	char	*line;
	//char	**map;

	fd = open("map.cub", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%d -- |%s|\n", ret, line);
	while (ret)
	{
		ret = get_next_line(fd, &line);

		printf("%d -- |%s|\n", ret, line);
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}