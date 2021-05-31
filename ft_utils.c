#include "cub3D.h"

double	check_overflow_angle(double angle)
{
	if (angle > (2 * PI))
		angle -= (2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}