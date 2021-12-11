/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:41 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:42 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	define_step(t_data * data, float angle)
{
	data->key.stepX = 0;
	data->key.stepY = 0;
	if ((angle > 0 && angle < (PI / 2)))
	{
		data->key.stepX = 1;
		data->key.stepY = 1;
	}
	if ((angle > (PI / 2) && angle < PI))
	{
		data->key.stepX = -1;
		data->key.stepY = 1;
	}
	if ((angle > PI && angle < (3 * PI / 2)))
	{
		data->key.stepX = -1;
		data->key.stepY = -1;
	}
	if ((angle > (3 * PI / 2) && angle < (2 * PI)))
	{
		data->key.stepX = 1;
		data->key.stepY = -1;
	}
	return (0);
}

int player_move(t_data *data, float angle, float l, int sign)
{
	int x;
	int y;
	float dist;

	dist = 0.3;
	angle = check_overflow_angle(angle);
	define_step(data, angle);
	x = (int)(data->px / data->cellsize + sign * (dist * data->key.stepX));
	y = (int)(data->py / data->cellsize + sign * (dist * data->key.stepY));
	if (data->map[x][(int)data->py / data->cellsize] == '0')
		data->px = data->px + sign * l * cosf(angle);
	if (data->map[(int)data->px / data->cellsize][y] == '0')
		data->py = data->py + sign * l * sinf(angle);
	return (0);
}

int	deal_key(t_data *data)
{
	float	l;

	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	l = (data->cellsize / 10) * 0.5;
	if (data->key.w == 1)
		player_move(data, data->angle, l, 1);
	if (data->key.s == 1)
		player_move(data, data->angle, l, -1);
	if (data->key.a == 1)
		player_move(data, (data->angle + (PI / 2)), l, 1);
	if (data->key.d == 1)
		player_move(data, (data->angle + (PI / 2)), l, -1);
	if (data->key.r == 1)
		data->angle -= 0.05;
	if (data->key.l == 1)
		data->angle += 0.05;
	data->angle = check_overflow_angle(data->angle);
	if (data->key.e == 1)
		close_window(data);
	make_image(data);
	return (0);
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == PLAYER_FORWARD)
		data->key.w = 1;
	if (keycode == PLAYER_BACK)
		data->key.s = 1;
	if (keycode == PLAYER_LEFT)
		data->key.a = 1;
	if (keycode == PLAYER_RIGHT)
		data->key.d = 1;
	if (keycode == CAMERA_RIGHT)
		data->key.r = 1;
	if (keycode == CAMERA_LEFT)
		data->key.l = 1;
	if (keycode == ESC)
		data->key.e = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == PLAYER_FORWARD)
		data->key.w = 0;
	if (keycode == PLAYER_BACK)
		data->key.s = 0;
	if (keycode == PLAYER_LEFT)
		data->key.a = 0;
	if (keycode == PLAYER_RIGHT)
		data->key.d = 0;
	if (keycode == CAMERA_RIGHT)
		data->key.r = 0;
	if (keycode == CAMERA_LEFT)
		data->key.l = 0;
	return (0);
}
