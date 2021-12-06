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
	int x;

	data->parsing.c = 0;
	ret = 1;
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char *) * 200);
	len = 0;
	x = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		printf("recup : %s\n", recup);
		//printf("check : %d\n", check_texture(recup, data));
		if(check_texture(recup, data))
		{
			data->map[x++] = ft_strdup(recup);
			break;
		}
	}
	data->color_sky = data->parsing.text_c;
	data->color_ground = data->parsing.text_f;


	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		printf("line : %s\n", recup);
		data->map[x] = ft_strdup(recup);
		if (ft_strlen(data->map[x]) > len)
			len = ft_strlen(data->map[x]);
		//printf("len|%zu\n", len);
		free(recup);
		x++;
		if (ret == 0)
		{
			data->map[x] = NULL;
			//printf("x|%d\n", x);
			data->map_heigth = x - 1;
			data->map_width = len - 1;
			print_minimap(data);
			break;
		}
	}
	return (0);
}

int	parsing(t_data *data)
{
	printf("coucou\n");
	if (recup("./map2.cub", data))
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
