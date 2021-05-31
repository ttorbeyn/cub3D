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

int	define_step(t_data *img)
{
	if ((img->ray.angle > 0 && img->ray.angle < PI / 2))
	{
		img->ray.stepY = 1;
		img->ray.stepX = 1;
	}
	if ((img->ray.angle > PI / 2 && img->ray.angle < PI))
	{
		img->ray.stepY = 1;
		img->ray.stepX = -1;
	}
	if ((img->ray.angle > PI && img->ray.angle < 2 * PI / 3))
	{
		img->ray.stepY = -1;
		img->ray.stepX = -1;
	}
	if ((img->ray.angle > 2 * PI / 3 && img->ray.angle < 2 * PI))
	{
		img->ray.stepY = -1;
		img->ray.stepX = 1;
	}
	return (0);
}

int player_forward(t_data *img, float l)
{
	int x;
	int y;
	float dist;

	dist = 0.2;
	x = (int)(img->px / img->cellsize + (dist * img->ray.stepX));
	y = (int)(img->py / img->cellsize + (dist * img->ray.stepY));
	if (img->map[x][y] == '0')
	{
		img->px += l * cosf(img->angle);
		img->py += l * sinf(img->angle);
	}
	return (0);
}
//int player_back(t_data *img)
//int player_left(t_data *img)
//int player_right(t_data *img)
/*
int camera_left(t_data *img)
int camera_right(t_data *img)
*/
int	deal_key(t_data *img)
{
	float	l;

	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	l = (img->cellsize / 10) * 0.3;
	if (img->key.w == 1)
		player_forward(img, l);
	if (img->key.s == 1)
	{
		img->px -= l * cosf(img->angle);
		img->py -= l * sinf(img->angle);
	}
	if (img->key.a == 1)
	{
		img->px -= l * cosf(img->angle + (PI / 2));
		img->py -= l * sinf(img->angle + (PI / 2));
	}
	if (img->key.d == 1)
	{
		img->px += l * cosf(img->angle + (PI / 2));
		img->py += l * sinf(img->angle + (PI / 2));
	}
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
