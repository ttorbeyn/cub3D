/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:32 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:34 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	draw_ray(t_data *data, int color)
{
	double	c;
	double	x;
	double	y;

	x = data->px;
	y = data->py;
	c = 0;
	while (c <= (data->ray.length * data->cellsize) && c < 800
		&& x > 0 && y > 0 && x < data->width && y < data->height)
	{
		my_mlx_pixel_put(data, x, y, color);
		x += (cosf(data->ray.angle));
		y += (sinf(data->ray.angle));
		c++;
	}
	if (!color)
		return (0);
	return (0);
}

int	draw_3D(t_data *data)
{
	double	len;
	double	start;
	double	i;
	double	x;
	double	y_step;
	double	offset;

	i = 0;
	offset = 0;
	len = data->height / data->ray.lengthf;
	y_step = data->text.height/len;
	if (len > data->height)
	{
		offset = (len - data->height)/2;
		len = data->height;
	}
	start = (data->height / 2) - (len / 2);
	data->ray.y = 0;
	while (i < start)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x] = data->color_sky;
		i++;
		data->ray.y++;
	}
	if (data->ray.side == 0)
	{
		x = (int)(data->ray.VsideDistY * data->text.width) % data->text.width;
		if (data->ray.angle > (PI / 2) && data->ray.angle < ((3 * PI) / 2))
			x = data->text.width - 1 - x;
	}
	else
	{
		x = (int)(data->ray.VsideDistX * data->text.width) % data->text.width;
		if (!(data->ray.angle > PI && data->ray.angle < (2 * PI)))
			x = data->text.width - 1 - x;
	}
	data->text.texx = x;
	data->text.texy = offset * y_step;
	data->text.texpos = (data->ray.y + (data->ray.y + len) / 2 + len / 2) * y_step;
	while (len > 0 && i < data->height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x] =
				data->text.addr[(int)data->text.texy * data->text.line_length / 4 + (int)data->text.texx];
		len--;
		i++;
		data->text.texy += y_step;
		data->ray.y++;
	}
	while (i < data->height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x] = data->color_ground;
		i++;
		data->ray.y++;
	}
	data->ray.x++;
	return (0);
}

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
				big_pixel(data, 0x000000FF, (((x + 1) * data->cellsize) - data->cellsize), ((y + 1) * data->cellsize), data->cellsize);
			//else
			//	big_pixel(data, 0x007F7F7F, (((x + 1) * data->cellsize) - data->cellsize), ((y + 1) * data->cellsize), data->cellsize);
			y++;
		}
		x++;
	}
	return (0);
}
