/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:09:54 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:09:55 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	is_left(double angle)
{
	if (angle > P2 && angle < P32)
		return (1);
	return (0);
}

int	is_down(double angle)
{
	if (angle > PI && angle < (2 * PI))
		return (1);
	return (0);
}

int	define_lenghtf(t_data *data)
{
	float	angle;

	data->ray.length = data->ray.lengthV;
	if (data->ray.lengthH < data->ray.lengthV)
	{
		data->ray.length = data->ray.lengthH;
		data->ray.VcoordX = data->ray.HcoordX;
		data->ray.VcoordY = data->ray.HcoordY;
		data->ray.side = 1;
	}
	angle = check_overflow_angle(data->angle - data->ray.angle);
	data->ray.lengthf = data->ray.length * cosf(angle);
	return (0);
}
