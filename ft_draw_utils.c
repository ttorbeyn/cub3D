/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:07:57 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:04 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	get_orientation(t_data *data)
{
	if (data->ray.step_x == -1 && data->ray.side == 0)
		return (0);
	else if (data->ray.step_x == 1 && data->ray.side == 0)
		return (1);
	else if (data->ray.step_y == -1)
		return (2);
	else if (data->ray.step_y == 1)
		return (3);
	return (-1);
}
