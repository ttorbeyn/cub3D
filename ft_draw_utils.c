/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:07:57 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:04 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	draw_ray(t_data *data, int color)
{
	double	c;
	double	x;
	double	y;

	x = data->px;
	y = data->py;
	c = 0;
	while (c < (data->ray.length * data->cellsize)
		&& x > 0 && y > 0 && x < data->win_height && y < data->win_width)
	{
		my_mlx_pixel_put(data, x, y, color);
		x += cosf(data->ray.angle);
		y += sinf(data->ray.angle);
		c++;
	}
	return (0);
}

int	get_orientation(t_data *data)
{
	if (data->ray.stepY == 1 && data->ray.side == 1)
		return (0);
	else if (data->ray.stepY == -1 && data->ray.side == 1)
		return (1);
	else if (data->ray.stepX == 1)
		return (2);
	else if (data->ray.stepX == -1)
		return (3);
	return (-1);
}

/*

int	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '1')
				big_pixel(data, 0x000000FF, (((x + 1) * data->cellsize)
						- data->cellsize), ((y + 1)
						* data->cellsize), data->cellsize);
			y++;
		}
		x++;
	}
	return (0);
}

*/
