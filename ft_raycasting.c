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
	data->ray.VsideDistX = 0;
	data->ray.VsideDistY = 0;
	data->ray.HsideDistX = 0;
	data->ray.HsideDistY = 0;
	data->ray.deltaDistX = 0;
	data->ray.deltaDistY = 0;
	data->ray.lengthV = 0;
	data->ray.lengthH = 0;
	data->ray.length = 0;
	data->ray.side = 0;
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
	data->ray.VsideDistX = data->ray.posX + data->ray.dx * data->ray.stepX;
	if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2))
		data->ray.VsideDistY = data->ray.posY + (tanf(data->ray.angle) * data->ray.dx * data->ray.stepX);
	while (c < 7 && data->ray.VsideDistX >= 0 && data->ray.VsideDistY >= 0
		&& data->ray.VsideDistX < 9 && data->ray.VsideDistY < 9)
	{
		x = (int)data->ray.VsideDistX;
		if ((data->ray.angle > PI / 2 && data->ray.angle < ((3 * PI) / 2)))
			x = (int)data->ray.VsideDistX - 1;
		if (data->map[x][(int)data->ray.VsideDistY] != '1')
		{
			data->ray.VsideDistX += data->ray.stepX;
			if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2))
				data->ray.VsideDistY += tanf(data->ray.angle) * data->ray.stepX;
			c++;
		}
		else
			c = 7;
	}
	data->ray.deltaDistX = data->ray.VsideDistX - data->ray.posX;
	data->ray.deltaDistY = data->ray.VsideDistY - data->ray.posY;
	data->ray.lengthV = hypot(data->ray.deltaDistX, data->ray.deltaDistY);
	return (0);
}

int	raycasting_horizontal(t_data *data)
{
	int	c;
	int	y;

	c = 0;
	if (data->ray.angle > 0 && data->ray.angle < PI)
	{
		data->ray.stepY = 1;
		data->ray.dy = 1.0 - (data->ray.posY - data->ray.mapY);
	}
	else if (data->ray.angle > PI && data->ray.angle < (2 * PI))
	{
		data->ray.stepY = -1;
		data->ray.dy = data->ray.posY - data->ray.mapY;
	}
	if (!(data->ray.angle == PI / 2 || data->ray.angle == 3 * PI / 2) && tanf(data->ray.angle) != 0)
		data->ray.HsideDistX = data->ray.posX + ((data->ray.dy * data->ray.stepY) / tanf(data->ray.angle));
	data->ray.HsideDistY = data->ray.posY + (data->ray.dy * data->ray.stepY);
	while (c < 7 && data->ray.HsideDistX >= 0 && data->ray.HsideDistY >= 0
		&& data->ray.HsideDistX <= 8 && data->ray.HsideDistY <= 8)
	{
		y = (int)data->ray.HsideDistY;
		if (data->ray.angle > PI && data->ray.angle < (2 * PI))
			y = (int)data->ray.HsideDistY - 1;
		if (data->map[(int)data->ray.HsideDistX][y] != '1')
		{
			if (data->ray.angle != PI / 2 && data->ray.angle != 3 * PI / 2 && tanf(data->ray.angle) != 0)
				data->ray.HsideDistX += data->ray.stepY / tanf(data->ray.angle);
			data->ray.HsideDistY += data->ray.stepY;
			c++;
		}
		else
			c = 7;
	}
	data->ray.deltaDistX = data->ray.HsideDistX - data->ray.posX;
	data->ray.deltaDistY = data->ray.HsideDistY - data->ray.posY;
	data->ray.lengthH = hypot(data->ray.deltaDistX, data->ray.deltaDistY);
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
		data->ray.length = data->ray.lengthV;
		if (data->ray.lengthV > data->ray.lengthH)
		{
			data->ray.length = data->ray.lengthH;
			data->ray.VsideDistX = data->ray.HsideDistX;
			data->ray.VsideDistY = data->ray.HsideDistY;
			data->ray.side = 1;
			color = 0x00808080;
		}
		angle = data->angle - data->ray.angle;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)
			angle += (2 * PI);
		data->ray.lengthf = data->ray.length * cosf(angle);
		//draw_3D(data);
		draw_ray(data, 0x0000FF00);
		data->ray.angle += (PI / 3) / (data->width);
		data->ray.angle = check_overflow_angle(data->ray.angle);
		x++;
	}
	draw_minimap(data);
	data->ray.angle = data->angle;
	raycasting_vertical(data);
	raycasting_horizontal(data);
	data->ray.length = data->ray.lengthV;
	if (data->ray.lengthV > data->ray.lengthH)
		data->ray.length = data->ray.lengthH;
	draw_ray(data, 0xFF0000);
	return (0);
}
