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

#include "cub3D.h"

int set_key(t_data *img)
{
	img->key.w = 0;
	img->key.a = 0;
	img->key.s = 0;
	img->key.d = 0;
	img->key.l = 0;
	img->key.r = 0;
	img->key.e = 0;
	return (0);
}

int	define_step(t_data * img, float angle)
{
	img->key.stepX = 0;
	img->key.stepY = 0;
	if ((angle > 0 && angle < (PI / 2)))
	{
		img->key.stepX = 1;
		img->key.stepY = 1;
	}
	if ((angle > (PI / 2) && angle < PI))
	{
		img->key.stepX = -1;
		img->key.stepY = 1;
	}
	if ((angle > PI && angle < (3 * PI / 2)))
	{
		img->key.stepX = -1;
		img->key.stepY = -1;
	}
	if ((angle > (3 * PI / 2) && angle < (2 * PI)))
	{
		img->key.stepX = 1;
		img->key.stepY = -1;
	}
	return (0);
}

int player_forward(t_data *img, float angle, float l)
{
	int x;
	int y;
	float dist;

	dist = 0.3;
	angle = check_overflow_angle(angle);
	define_step(img, angle);
	x = (int)(img->px / img->cellsize + (dist * img->key.stepX));
	y = (int)(img->py / img->cellsize + (dist * img->key.stepY));
	if (img->map[x][(int)img->py / img->cellsize] == '0')
		img->px += l * cosf(angle);
	if (img->map[(int)img->px / img->cellsize][y] == '0')
		img->py += l * sinf(angle);
	return (0);
}

int player_back(t_data *img, float angle, float l)
{
	int x;
	int y;
	float dist;

	dist = 0.3;
	angle = check_overflow_angle(angle);
	define_step(img, angle);
	x = (int)(img->px / img->cellsize - (dist * img->key.stepX));
	y = (int)(img->py / img->cellsize - (dist * img->key.stepY));
	if (img->map[x][(int)img->py / img->cellsize] == '0')
		img->px -= l * cosf(angle);
	if (img->map[(int)img->px / img->cellsize][y] == '0')
		img->py -= l * sinf(angle);
	return (0);
}

int	deal_key(t_data *img)
{
	float	l;

	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	l = (img->cellsize / 10) * 0.3;
	if (img->key.w == 1)
		player_forward(img, img->angle, l);
	if (img->key.s == 1)
		player_back(img, img->angle, l);
	if (img->key.a == 1)
		player_back(img, (img->angle + (PI / 2)), l);
	if (img->key.d == 1)
		player_forward(img, (img->angle + (PI / 2)), l);
	if (img->key.r == 1)
		img->angle += 0.03;
	if (img->key.l == 1)
		img->angle -= 0.03;
	img->angle = check_overflow_angle(img->angle);
	if (img->key.e == 1)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	make_image(img);
	return (0);
}

int	key_pressed(int keycode, t_data *img)
{
	if (keycode == PLAYER_FORWARD)
		img->key.w = 1;
	if (keycode == PLAYER_BACK)
		img->key.s = 1;
	if (keycode == PLAYER_LEFT)
		img->key.a = 1;
	if (keycode == PLAYER_RIGHT)
		img->key.d = 1;
	if (keycode == CAMERA_RIGHT)
		img->key.r = 1;
	if (keycode == CAMERA_LEFT)
		img->key.l = 1;
	if (keycode == ESC)
		img->key.e = 1;
	return (0);
}

int	key_released(int keycode, t_data *img)
{
	if (keycode == PLAYER_FORWARD)
		img->key.w = 0;
	if (keycode == PLAYER_BACK)
		img->key.s = 0;
	if (keycode == PLAYER_LEFT)
		img->key.a = 0;
	if (keycode == PLAYER_RIGHT)
		img->key.d = 0;
	if (keycode == CAMERA_RIGHT)
		img->key.r = 0;
	if (keycode == CAMERA_LEFT)
		img->key.l = 0;
	return (0);
}
