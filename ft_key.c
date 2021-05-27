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

double	check_overflow_angle(double angle)
{
	if (angle > (2 * PI))
		angle -= (2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

int	deal_key(int keycode, t_data *img)
{
	int	l;

	l = img->cellsize / 10;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	if (keycode == PLAYER_FORWARD)
	{
		img->px += l * cosf(img->angle);
		img->py += l * sinf(img->angle);
	}
	if (keycode == PLAYER_BACK)
	{
		img->px -= l * cosf(img->angle);
		img->py -= l * sinf(img->angle);
	}
	if (keycode == PLAYER_LEFT)
	{
		img->px -= l * cosf(img->angle + (PI / 2));
		img->py -= l * sinf(img->angle + (PI / 2));
	}
	if (keycode == PLAYER_RIGHT)
	{
		img->px += l * cosf(img->angle + (PI / 2));
		img->py += l * sinf(img->angle + (PI / 2));
	}
	if (keycode == CAMERA_RIGHT)
		img->angle += 0.1;
	if (keycode == CAMERA_LEFT)
		img->angle -= 0.1;
	img->angle = check_overflow_angle(img->angle);
	if (keycode == ESC)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	make_image(img);
	return (0);
}
