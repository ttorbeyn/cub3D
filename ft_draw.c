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

#include "includes/cub3D.h"

int	draw_ceiling(t_data *data)
{
	while (data->three_d.i < data->three_d.start)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->parsing.text_c;
		data->three_d.i++;
		data->ray.y++;
	}
	return (0);
}

int	draw_wall(t_data *data, int side)
{
	while (data->three_d.len > 0 && data->three_d.i < data->win_height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->text[side].addr[(int)data->text[side].texy
			* data->text[side].line_length / 4 + (int)data->text[side].texx];
		data->three_d.len--;
		data->three_d.i++;
		data->text[side].texy += data->three_d.y_step;
		data->ray.y++;
	}
	return (0);
}

int	draw_floor(t_data *data)
{
	while (data->three_d.i < data->win_height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->parsing.text_f;
		data->three_d.i++;
		data->ray.y++;
	}
	return (0);
}

int	define_coord_text(t_data *data, int side)
{
	double	x;

	if (data->ray.side == 0)
	{
		x = (int)(data->ray.v_coord_y * data->text[side].width)
			% data->text[side].width;
		if (data->ray.angle > (PI / 2) && data->ray.angle < ((3 * PI) / 2))
			x = data->text[side].width - 1 - x;
	}
	else
	{
		x = (int)(data->ray.v_coord_x * data->text[side].width)
			% data->text[side].width;
		if (!(data->ray.angle > PI && data->ray.angle < (2 * PI)))
			x = data->text[side].width - 1 - x;
	}
	data->text[side].texx = x;
	data->text[side].texy = data->three_d.offset * data->three_d.y_step;
	data->text[side].texpos = (data->ray.y + (data->ray.y
				+ data->three_d.len) / 2 + data->three_d.len / 2)
		* data->three_d.y_step;
	return (0);
}

int	draw_3d(t_data *data)
{
	int		side;

	side = get_orientation(data);
	data->three_d.i = 0;
	data->three_d.offset = 0;
	data->three_d.len = data->win_height / data->ray.length_f;
	data->three_d.y_step = data->text[side].height / data->three_d.len;
	if (data->three_d.len > data->win_height)
	{
		data->three_d.offset = (data->three_d.len - data->win_height) / 2;
		data->three_d.len = data->win_height;
	}
	data->three_d.start = (data->win_height / 2) - (data->three_d.len / 2);
	data->ray.y = 0;
	draw_ceiling(data);
	define_coord_text(data, side);
	draw_wall(data, side);
	draw_floor(data);
	data->ray.x++;
	return (0);
}
