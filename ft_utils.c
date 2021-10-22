#include "cub3D.h"

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
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			printf("%c", data->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}