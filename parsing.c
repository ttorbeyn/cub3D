#include "cub3D.h"

typedef struct	s_parsing
{
	int res_x;
	int res_y;
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;
	char *text_s;
	char *text_f;
	char *text_c;
}				t_parsing;

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
char	**ft_map(int fd)
{
	int		ret;
	char	*line;
	char	**map;
	int x;

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


void	ft_parsing(void)
{
	char **map;
	int x;
	int fd;

	x = 0;
	fd = open("map.cub", O_RDONLY);
	map = ft_map(fd);
	while (map[x])
	{
		printf("%s\n", map[x]);
		x++;
	}
}

int main(void)
{
	ft_parsing();
	return (0);
}