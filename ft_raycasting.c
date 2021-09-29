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

#include "cub3D.h"
#include <stdio.h>

int	set_ray(t_data *data)
{
	data->ray.posX = data->px / data->cellsize;
	data->ray.posY = data->py / data->cellsize;
	data->ray.mapX = (int)(data->ray.posX);
	data->ray.mapY = (int)(data->ray.posY);
	data->ray.dx = 0;
	data->ray.dy = 0;
	data->ray.sideDistX = 0;
	data->ray.sideDistY = 0;
	data->ray.deltaDistX = 0;
	data->ray.deltaDistY = 0;
	data->ray.lengthx = 0;
	data->ray.lengthy = 0;
	data->ray.length = 0;
	return (0);
}

int	raycasting_vertical(t_data *data)
{
	int	c;
	int	x;

	c = 0;
	if ((data->ray.angle >= PI / 2 && data->ray.angle <= ((3 * PI) / 2)))
	{
		data->ray.stepX = -1;
		data->ray.dx = data->ray.posX - data->ray.mapX;
	}
	else if ((data->ray.angle < PI / 2) || (data->ray.angle > ((3 * PI) / 2)))
	{
		data->ray.stepX = 1;
		data->ray.dx = 1.0 - (data->ray.posX - data->ray.mapX);
	}
	data->ray.sideDistX = data->ray.posX + data->ray.dx * data->ray.stepX;
	if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2))
		data->ray.sideDistY = data->ray.posY + (tanf(data->ray.angle) * data->ray.dx * data->ray.stepX);
	while (c < 7 && data->ray.sideDistX >= 0 && data->ray.sideDistY >= 0
		&& data->ray.sideDistX <= 8 && data->ray.sideDistY <= 8)
	{
		x = (int)data->ray.sideDistX;
		if ((data->ray.angle > PI / 2 && data->ray.angle < ((3 * PI) / 2)))
			x = (int)data->ray.sideDistX - 1;
		if (data->map[x][(int)data->ray.sideDistY] != '1')
		{
			data->ray.sideDistX += data->ray.stepX;
			if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2))
				data->ray.sideDistY += tanf(data->ray.angle) * data->ray.stepX;
			c++;
		}
		else
			c = 7;
	}
	data->ray.deltaDistX = data->ray.sideDistX - data->ray.posX;
	data->ray.deltaDistY = data->ray.sideDistY - data->ray.posY;
	data->ray.lengthx = hypot(data->ray.deltaDistX, data->ray.deltaDistY);
	return (0);
}

int	raycasting_horizontal(t_data *data)
{
	int	c;
	int	y;

	c = 0;
	if ((data->ray.angle > 0 && data->ray.angle < PI))
	{
		data->ray.stepY = 1;
		data->ray.dy = 1.0 - (data->ray.posY - data->ray.mapY);
	}
	else if ((data->ray.angle > PI && data->ray.angle < (2 * PI)))
	{
		data->ray.stepY = -1;
		data->ray.dy = data->ray.posY - data->ray.mapY;
	}
	if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2) && tanf(data->ray.angle) != 0)
		data->ray.sideDistX = data->ray.posX + ((data->ray.dy * data->ray.stepY) / tanf(data->ray.angle));
	data->ray.sideDistY = data->ray.posY + (data->ray.dy * data->ray.stepY);
	while (c < 7 && data->ray.sideDistX >= 0 && data->ray.sideDistY >= 0
		&& data->ray.sideDistX <= 8 && data->ray.sideDistY <= 8)
	{
		y = (int)data->ray.sideDistY;
		if ((data->ray.angle > PI && data->ray.angle < (2 * PI)))
			y = (int)data->ray.sideDistY - 1;
		if (data->map[(int)data->ray.sideDistX][y] != '1')
		{
			if (data->ray.angle != PI / 2 && data->ray.angle != 3 * PI / 2 && tanf(data->ray.angle) != 0)
				data->ray.sideDistX += data->ray.stepY / tanf(data->ray.angle);
			data->ray.sideDistY += data->ray.stepY;
			c++;
		}
		else
			c = 7;
	}
	data->ray.deltaDistX = data->ray.sideDistX - data->ray.posX;
	data->ray.deltaDistY = data->ray.sideDistY - data->ray.posY;
	data->ray.lengthy = hypot(data->ray.deltaDistX, data->ray.deltaDistY);
	return (0);
}

int	raycasting(t_data *data)
{
	float	angle;
	int		x;
	int		color;

	data->ray.angle = check_overflow_angle(data->angle - (PI / 6));
	data->ray.x = 0;
	x = 0;


	while (x < data->width)
	{
		color = 0x00696969;
		set_ray(data);
		raycasting_vertical(data);
		raycasting_horizontal(data);
		data->ray.length = data->ray.lengthx;
		if (data->ray.lengthx > data->ray.lengthy)
		{
			data->ray.length = data->ray.lengthy;
			color = 0x00808080;
		}
		angle = data->angle - data->ray.angle;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)
			angle += (2 * PI);
		data->ray.lengthf = data->ray.length * cosf(angle);
		draw_3D(data, color);
		draw_ray(data, 0x0000FF00);
		data->ray.angle += (PI / 3) / (data->width);
		data->ray.angle = check_overflow_angle(data->ray.angle);
		x++;
	}
	draw_minimap(data);
	data->ray.angle = data->angle;
	raycasting_vertical(data);
	raycasting_horizontal(data);
	data->ray.length = data->ray.lengthx;
	if (data->ray.lengthx > data->ray.lengthy)
		data->ray.length = data->ray.lengthy;
	draw_ray(data, 0xFF0000);
	return (0);
}
