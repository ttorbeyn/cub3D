/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:11:45 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/20 20:11:48 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

/*

	Vérifie que la map ne soit composée que de "01NSWE "

*/

int	check_valid_char_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (strchr("01 NSWE", data->map[x][y]))
				y++;
			else
				return (1);
		}
		x++;
	}
	return (0);
}

/*

	Vérifie qu'il y ait pas plusieurs fois une position de départ pour
 	le joueur (N, S, E, W).
 	Attribue la position du joueur de base.
 	Change la lettre en un 0.

*/

int	check_coordinate(t_data *data)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (is_coordinate(data->map[x][y]))
			{
				if (c++ < 1)
					get_coordinate(data, x, y);
				else
					return (print_error(7, data));
			}
		}
	}
	if (!c)
		return (print_error(8, data));
	return (0);
}

int	check_outline(t_data *data)
{
	int	x;
	int	y;
	int	c;

	y = -1;
	c = 0;
	while (++y < data->map_width)
	{
		if (!strchr(" 1", data->map[0][y])
			&& !strchr(" 1", data->map[data->map_height - 1][y]))
			return (print_error(9, data));
		if (strchr(" ", data->map[data->map_height - 1][y]))
			c++;
	}
	x = 0;
	while (x < data->map_height)
	{
		if (!strchr(" 1", data->map[x][0])
			&& !strchr(" 1", data->map[x][data->map_width - 1]))
			return (print_error1(10, data));
		x++;
	}
	if (c >= data->map_width)
		return (print_error1(11, data));
	return (0);
}

int	check_wall(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	while (x < data->map_height - 1)
	{
		y = 1;
		while (y < data->map_width - 1)
		{
			while (is_space(data->map[x][y]) && y < data->map_width - 1)
				y++;
			if (data->map[x][y] == '0' && check_surround(data, x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (check_valid_char_map(data))
		return (print_error(6, data));
	if (check_coordinate(data))
		return (1);
	if (check_outline(data))
		return (1);
	if (check_wall(data))
		return (print_error(9, data));
	get_angle(data);
	return (0);
}
