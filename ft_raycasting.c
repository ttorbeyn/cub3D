/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:54 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:56 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	define_step_x(t_data *data)
{
 	if (data->ray.angle == P2 || data->ray.angle == P32)
		return (1);
	if (is_left(data->ray.angle))
	{
		data->ray.stepX = -1;
		data->ray.dx = 0.0 - (data->ray.posX - data->ray.mapX);
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.dx = 1.0 - (data->ray.posX - data->ray.mapX);
	}
	data->ray.dy = tanf(data->ray.angle) * data->ray.dx;
	data->ray.VcoordX = data->ray.posX + data->ray.dx;
	data->ray.VcoordY = data->ray.posY + data->ray.dy;
	return (0);
}

int	raycasting_vertical(t_data *data)
{
	int	c;
	int	x;

	c = 1;
	if (define_step_x(data))
 		return (0);
	while (c < data->map_height && data->ray.VcoordX >= 0
		&& data->ray.VcoordY >= 0 && data->ray.VcoordX < data->map_height
		&& data->ray.VcoordY < data->map_width)
	{
		x = (int)data->ray.VcoordX;
		if (is_left(data->ray.angle) && x > 0)
			x -= 1;
		if (data->map[x][(int)data->ray.VcoordY] != '1' && c++)
		{
			data->ray.VcoordY += tanf(data->ray.angle) * data->ray.stepX;
			data->ray.VcoordX += data->ray.stepX;
		}
		else
			break ;
	}
	data->ray.lengthV = hypot((data->ray.VcoordX - data->ray.posX),
			(data->ray.VcoordY - data->ray.posY));
	return (0);
}

int	define_step_y(t_data *data)
{
	if (data->ray.angle == PI || data->ray.angle == 0)
		return (1);
	if (is_down(data->ray.angle))
	{
		data->ray.stepY = -1;
		data->ray.dy = 0.0 - (data->ray.posY - data->ray.mapY);
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.dy = 1.0 - (data->ray.posY - data->ray.mapY);
	}
	data->ray.dx = 0;
	if (data->ray.angle != P2 || data->ray.angle != P32)
		data->ray.dx = data->ray.dy / tanf(data->ray.angle);
	data->ray.HcoordX = data->ray.posX + data->ray.dx;
	data->ray.HcoordY = data->ray.posY + data->ray.dy;
	return (0);
}

int	raycasting_horizontal(t_data *data)
{
	int	c;
	int	y;

	c = 1;
	if (define_step_y(data))
		return (0);
	while (c < data->map_width && data->ray.HcoordX >= 0
		&& data->ray.HcoordY >= 0 && data->ray.HcoordX < data->map_height
		&& data->ray.HcoordY < data->map_width)
	{
		y = (int)data->ray.HcoordY;
		if (is_down(data->ray.angle) && y > 0)
			y -= 1;
		if (data->map[(int)data->ray.HcoordX][y] != '1' && c++)
		{
			if (data->ray.angle != P2 || data->ray.angle != P32)
				data->ray.HcoordX += data->ray.stepY / tanf(data->ray.angle);
			data->ray.HcoordY += data->ray.stepY;
		}
		else
			break ;
	}
	data->ray.lengthH = hypot((data->ray.HcoordX - data->ray.posX),
			(data->ray.HcoordY - data->ray.posY));
	return (0);
}

int	raycasting(t_data *data)
{
	int		x;

	data->ray.angle = check_overflow_angle(data->angle + (PI / 6));
	data->ray.x = 0;
	x = 0;
	while (x < data->win_width)
	{
		set_ray(data);
		raycasting_vertical(data);
		raycasting_horizontal(data);
		define_lenghtf(data);
		draw_3d(data);
	//	draw_ray(data, 0x0000FF00);
		data->ray.angle -= (PI / 3) / data->win_width;
		data->ray.angle = check_overflow_angle(data->ray.angle);
		x++;
	}
	//draw_minimap(data);
	return (0);
}
