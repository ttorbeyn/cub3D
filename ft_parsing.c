#include "includes/cub3D.h"

/*

	Ouvre et récupere la map grace a un get_next_line
 	Defini la hauteur et la longueur de la map

*/


int	recup(char *file, t_data *data)
{
	int ret;
	int fd;
	char *recup;
	size_t len;
	char	*line;
	int x;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		if(check_texture(recup, data))
			return (0);
	}
	data->map = malloc(sizeof(char *) * 200);
	len = 0;
	x = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		data->map[x] = ft_strdup(line);
		if (ft_strlen(data->map[x]) > len)
			len = ft_strlen(data->map[x]);
		//printf("len|%zu\n", len);
		free(line);
		x++;
		if (ret == 0)
		{
			data->map[x] = NULL;
			//printf("x|%d\n", x);
			data->map_heigth = x - 1;
			data->map_width = len - 1;
			return (0);
		}
	}
	printf("NO|%s|\n", data->parsing.text_no);
	printf("SO|%s|\n", data->parsing.text_so);
	printf("WE|%s|\n", data->parsing.text_we);
	printf("EA|%s|\n", data->parsing.text_ea);
	printf("F|%d|\n", data->parsing.text_f);
	printf("C|%d|\n", data->parsing.text_c);
	data->color_sky = data->parsing.text_c;
	data->color_ground = data->parsing.text_f;
	//printf("hello i am here\n");

	return (0);
}

int	parsing(t_data *data)
{
	if (recup("./map.cub", data))
		return (2);
	if (check_valid_char_map(data))
	{
		printf("NOT GOOD CHAR");
		return (1);
	}
	if (check_coordinate(data))
	{
		printf("hello1\n");
		return (1);
	}
	if (check_map(data))
		return (1);

	return (0);
}
