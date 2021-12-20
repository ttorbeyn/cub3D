/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:09:06 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:09:07 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	get_angle(t_data *data)
{
	if (data->orientation == 'E')
		data->angle = PI / 2;
	if (data->orientation == 'O')
		data->angle = (3 * PI) / 2;
	if (data->orientation == 'N')
		data->angle = PI;
	if (data->orientation == 'S')
		data->angle = 0;
	return (0);
}

int	get_coordinate(t_data *data, int x, int y)
{
	data->px = x * data->cellsize + (data->cellsize / 2);
	data->py = y * data->cellsize + (data->cellsize / 2);
	data->orientation = data->map[x][y];
	data->map[x][y] = '0';
	return (0);
}
