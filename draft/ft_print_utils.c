/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:01:53 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/20 21:01:54 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	print_minimap(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		printf("%s\n", data->map[x]);
		x++;
	}
	return (0);
}

int	print_textures(t_data *data)
{
	printf("NO : |%s|\n", data->parsing.text_no);
	printf("SO : |%s|\n", data->parsing.text_so);
	printf("EA : |%s|\n", data->parsing.text_ea);
	printf("WE : |%s|\n", data->parsing.text_we);
	printf("C : |%d|\n", data->parsing.text_c);
	printf("F : |%d|\n", data->parsing.text_f);
	return (0);
}

int	print_outlines(t_data *data)
{
	int	x;

	x = 0;
	printf("first line : |%s|\n", data->map[0]);
	printf("last line : |%s|\n", data->map[data->map_height - 1]);
	printf("first column : |");
	while (x < data->map_height)
	{
		printf("%c", data->map[x][0]);
		x++;
	}
	printf("|\n");
	printf("last column : |");
	x = 0;
	while (x < data->map_height)
	{
		printf("%c", data->map[x][data->map_width - 1]);
		x++;
	}
	printf("|\n");
	return (0);
}

/*

int	draw_ray_ex(t_data *data, int color, double angle)
{
	double	c;
	double	x;
	double	y;

	x = 250;
	y = 250;
	c = 0;
	//printf("h : %d\n", data->height);
	while (c < 20 && x > 0 && y > 0 && x < data->width && y < data->height)
	{
		my_mlx_pixel_put(data, y, x, 0x0000FF00);
		x += cosf(angle);
		y += sinf(angle);
		c++;
	}
	while (c < 200 && x > 0 && y > 0 && x < data->width && y < data->height)
	{
		my_mlx_pixel_put(data, y, x, color);
		x += cosf(angle);
		y += sinf(angle);
		c++;
	}
	return (0);
}

*/

int	draw_ray_ex(t_data *data, int color, double angle)
{
	double	c;
	double	x;
	double	y;

	x = 250;
	y = 250;
	c = 0;
	if (!angle)
		return (0);
	while (c < 20 && x > 0 && y > 0 && x < data->win_width
		&& y < data->win_height)
	{
		my_mlx_pixel_put(data, x, y, 0x0000FF00);
		x++;
		c++;
	}
	while (c < 500 && x > 0 && y > 0 && x < data->win_width
		&& y < data->win_height)
	{
		my_mlx_pixel_put(data, x, y, color);
		x++;
		c++;
	}
	return (0);
}
