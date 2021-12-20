/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:08:54 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:56 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	recup_map2(t_data *data, int ret, int x, int y)
{
	int		len;

	while (ret == 1)
	{
		ret = get_next_line(data->fd, &data->recup);
		len = ft_strlen(data->recup);
		data->map[x] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[x])
			return (print_error(14, data));
		y = 0;
		while (y < data->map_width)
		{
			if (y < len && (data->recup[y] == '0'
					|| is_coordinate(data->recup[y]) || data->recup[y] == '1'))
				data->map[x][y] = data->recup[y];
			else
				data->map[x][y] = ' ';
			y++;
		}
		data->map[x][y] = '\0';
		x++;
		free(data->recup);
	}
	data->map[x] = NULL;
	return (0);
}

int	recup_map(t_data *data, char *file)
{
	int		x;
	int		y;
	int		ret;

	x = 0;
	ret = 1;
	data->fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (print_error(14, data));
	while (x < data->parsing.map_line)
	{
		get_next_line(data->fd, &data->recup);
		x++;
		free(data->recup);
	}
	x = 0;
	y = 0;
	recup_map2(data, ret, x, y);
	close(data->fd);
	return (0);
}
