/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:08:25 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:27 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	define_step(t_data *data, float angle)
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
