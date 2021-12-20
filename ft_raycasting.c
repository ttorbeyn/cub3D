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

int	define_step_y(t_data *data)
{
	if (data->ray.angle == PI || data->ray.angle == 0)
		return (1);
	if (is_down(data->ray.angle))
	{
		data->ray.step_y = -1;
		data->ray.dy = 0.0 - (data->ray.pos_y - data->ray.map_y);
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.dy = 1.0 - (data->ray.pos_y - data->ray.map_y);
	}
	data->ray.dx = 0;
	if (data->ray.angle != P2 || data->ray.angle != P32)
		data->ray.dx = data->ray.dy / tanf(data->ray.angle);
	data->ray.h_coord_x = data->ray.pos_x + data->ray.dx;
	data->ray.h_coord_y = data->ray.pos_y + data->ray.dy;
	return (0);
}

int	raycasting_horizontal(t_data *data)
{
	int	c;
	int	y;

	c = 1;
	if (define_step_y(data))
		return (0);
	while (c < data->map_width && data->ray.h_coord_x >= 0
		&& data->ray.h_coord_y >= 0 && data->ray.h_coord_x < data->map_height
		&& data->ray.h_coord_y < data->map_width)
	{
		y = (int)data->ray.h_coord_y;
		if (is_down(data->ray.angle) && y > 0)
			y -= 1;
		if (data->map[(int)data->ray.h_coord_x][y] != '1' && c++)
		{
			if (data->ray.angle != P2 || data->ray.angle != P32)
				data->ray.h_coord_x += data->ray.step_y / tanf(data->ray.angle);
			data->ray.h_coord_y += data->ray.step_y;
		}
		else
			break ;
	}
	data->ray.length_h = hypot((data->ray.h_coord_x - data->ray.pos_x),
			(data->ray.h_coord_y - data->ray.pos_y));
	return (0);
}

int	define_step_x(t_data *data)
{
	if (data->ray.angle == P2 || data->ray.angle == P32)
		return (1);
	if (is_left(data->ray.angle))
	{
		data->ray.step_x = -1;
		data->ray.dx = 0.0 - (data->ray.pos_x - data->ray.map_x);
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.dx = 1.0 - (data->ray.pos_x - data->ray.map_x);
	}
	data->ray.dy = tanf(data->ray.angle) * data->ray.dx;
	data->ray.v_coord_x = data->ray.pos_x + data->ray.dx;
	data->ray.v_coord_y = data->ray.pos_y + data->ray.dy;
	return (0);
}

int	raycasting_vertical(t_data *data)
{
	int	c;
	int	x;

	c = 1;
	if (define_step_x(data))
		return (0);
	while (c < data->map_height && data->ray.v_coord_x >= 0
		&& data->ray.v_coord_y >= 0 && data->ray.v_coord_x < data->map_height
		&& data->ray.v_coord_y < data->map_width)
	{
		x = (int)data->ray.v_coord_x;
		if (is_left(data->ray.angle) && x > 0)
			x -= 1;
		if (data->map[x][(int)data->ray.v_coord_y] != '1' && c++)
		{
			data->ray.v_coord_y += tanf(data->ray.angle) * data->ray.step_x;
			data->ray.v_coord_x += data->ray.step_x;
		}
		else
			break ;
	}
	data->ray.length_v = hypot((data->ray.v_coord_x - data->ray.pos_x),
			(data->ray.v_coord_y - data->ray.pos_y));
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
		data->ray.angle -= (PI / 3) / data->win_width;
		data->ray.angle = check_overflow_angle(data->ray.angle);
		x++;
	}
	return (0);
}
