#include "includes/cub3D.h"

double	check_overflow_angle(double angle)
{
	if (angle > (2 * PI))
		angle -= (2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

int	print_minimap(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		printf("%s\n", data->map[x]);
		x++;
	}
	return (0);
}

int	print_textures(t_data *data)
{
	printf("NO : |%s|\n", data->parsing.text_no);
	printf("SO : |%s|\n", data->parsing.text_so);
	printf("EA : |%s|\n", data->parsing.text_ea);
	printf("WE : |%s|\n", data->parsing.text_we);
	printf("C : |%d|\n", data->parsing.text_c);
	printf("F : |%d|\n", data->parsing.text_f);
	return (0);
}

int	print_outlines(t_data *data)
{
	int x = 0;
	printf("first line : |%s|\n", data->map[0]);
	printf("last line : |%s|\n", data->map[data->map_heigth - 1]);
	printf("first column : |");
	while (x < data->map_heigth)
	{
		printf("%c", data->map[x][0]);
		x++;
	}
	printf("|\n");
	printf("last column : |");
	x = 0;
	while (x < data->map_heigth)
	{
		printf("%c", data->map[x][data->map_width - 1]);
		x++;
	}
	printf("|\n");
	return (0);
}