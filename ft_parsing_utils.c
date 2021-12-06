#include "includes/cub3D.h"

int is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == 0)
		return (1);
	return (0);
}

int	is_coordinate(char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (1);
	return (0);
}
