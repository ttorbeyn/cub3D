/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:10:16 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:10:17 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

double	check_overflow_angle(double angle)
{
	if (angle > (2 * PI))
		angle -= (2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->addr + (y * data->line_length / 4 + x);
	*dst = color;
}
