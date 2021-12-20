/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:10:08 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:10:11 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	set_ray(t_data *data)
{
	data->ray.pos_x = (data->px) / data->cellsize ;
	data->ray.pos_y = (data->py) / data->cellsize;
	data->ray.map_x = (int)(data->ray.pos_x);
	data->ray.map_y = (int)(data->ray.pos_y);
	data->ray.dx = 0;
	data->ray.dy = 0;
	data->ray.v_coord_x = 0;
	data->ray.v_coord_y = 0;
	data->ray.h_coord_x = 0;
	data->ray.h_coord_y = 0;
	data->ray.length_v = 0;
	data->ray.length_h = 0;
	data->ray.length = 0;
	data->ray.side = 0;
	return (0);
}

int	set_data(t_data *data)
{
	data->cellsize = 20;
	data->win_height = 1000;
	data->win_width = 2000;
	data->userheight = data->cellsize / 20;
	data->map_width = 0;
	data->map_height = 0;
	data->r = 0;
	data->g = 0;
	data->b = 0;
	return (0);
}

int	set_key(t_data *data)
{
	data->key.w = 0;
	data->key.a = 0;
	data->key.s = 0;
	data->key.d = 0;
	data->key.l = 0;
	data->key.r = 0;
	data->key.e = 0;
	return (0);
}

int	set_parsing(t_data *data)
{
	data->parsing.c = 1;
	data->parsing.map_line = 0;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
	data->parsing.text_ea = NULL;
	data->parsing.text_we = NULL;
	data->parsing.text_c = -1;
	data->parsing.text_f = -1;
	return (0);
}

int	set(t_data *data)
{
	set_data(data);
	set_key(data);
	set_parsing(data);
	return (0);
}
