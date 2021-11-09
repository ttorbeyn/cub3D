/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:47 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:49 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->addr + (y * data->line_length / 4 + x);
	*dst = color;
}

int	big_pixel(t_data *data, int color, int i, int j, int l)
{
	int	x;
	int	y;

	x = 0;
	while (x < l)
	{
		j -= l;
		y = 0;
		while (y < l)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
			y++;
		}
		i++;
		x++;
	}
	if (!color || !data)
		return (0);
	return (0);
}
