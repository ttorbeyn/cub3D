#include "includes/cub3D.h"

int	parsing(t_data *data)
{
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
	if (recup("./text.cub", data))
		return (2);
	return (0);
}
