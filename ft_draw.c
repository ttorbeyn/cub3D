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
	while (data->threeD.i < data->threeD.start)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->parsing.text_c;
		data->threeD.i++;
		data->ray.y++;
	}
	return (0);
}

int	draw_wall(t_data *data, int side)
{
	while (data->threeD.len > 0 && data->threeD.i < data->win_height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->text[side].addr[(int)data->text[side].texy
			* data->text[side].line_length / 4 + (int)data->text[side].texx];
		data->threeD.len--;
		data->threeD.i++;
		data->text[side].texy += data->threeD.y_step;
		data->ray.y++;
	}
	return (0);
}

int	draw_floor(t_data *data)
{
	while (data->threeD.i < data->win_height)
	{
		data->addr[(int)data->ray.y * data->line_length / 4 + (int)data->ray.x]
			= data->parsing.text_f;
		data->threeD.i++;
		data->ray.y++;
	}
	return (0);
}

int	define_coord_text(t_data *data, int side)
{
	double	x;

	if (data->ray.side == 0)
	{
		x = (int)(data->ray.VcoordY * data->text[side].width)
			% data->text[side].width;
		if (data->ray.angle > (PI / 2) && data->ray.angle < ((3 * PI) / 2))
			x = data->text[side].width - 1 - x;
	}
	else
	{
		x = (int)(data->ray.VcoordX * data->text[side].width)
			% data->text[side].width;
		if (!(data->ray.angle > PI && data->ray.angle < (2 * PI)))
			x = data->text[side].width - 1 - x;
	}
	data->text[side].texx = x;
	data->text[side].texy = data->threeD.offset * data->threeD.y_step;
	data->text[side].texpos = (data->ray.y + (data->ray.y
				+ data->threeD.len) / 2 + data->threeD.len / 2)
		* data->threeD.y_step;
	return (0);
}

int	draw_3d(t_data *data)
{
	int		side;

	side = get_orientation(data);
	data->threeD.i = 0;
	data->threeD.offset = 0;
	data->threeD.len = data->win_height / data->ray.lengthf;
	data->threeD.y_step = data->text[side].height / data->threeD.len;
	if (data->threeD.len > data->win_height)
	{
		data->threeD.offset = (data->threeD.len - data->win_height) / 2;
		data->threeD.len = data->win_height;
	}
	data->threeD.start = (data->win_height / 2) - (data->threeD.len / 2);
	data->ray.y = 0;
	draw_ceiling(data);
	define_coord_text(data, side);
	draw_wall(data, side);
	draw_floor(data);
	data->ray.x++;
	return (0);
}
