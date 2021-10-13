/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:32 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:34 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int textures[]=               //all 32x32 textures
		{
				//Checkerboard
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		};


int	draw_ray(t_data *data, int color)
{
	double	c;
	double	x;
	double	y;

	x = data->px;
	y = data->py;
	c = 0;
	while (c <= (data->ray.length * data->cellsize) && c < 800
		&& x > 0 && y > 0 && x < data->width && y < data->height)
	{
		my_mlx_pixel_put(data, x, y, color);
		x += (cosf(data->ray.angle));
		y += (sinf(data->ray.angle));
		c++;
	}
	return (0);
}
/*
int	draw_text(t_data *data)
{
	double len;

	len = data->text.height / data->ray.lengthf;
	if (len >= data->text.height)
		len = data->text.height;
	data->ray.y = (data->text.height / 2) - (len / 2);
	while (len > 0)
	{
		my_mlx_pixel_put(data, data->ray.x, data->ray.y, 0x000000FF);
		//data->data.addr[y * data->data.line_length / 4 + x] = recup->texture[data->t.texdir].addr[recup->t.texy * recup->texture[data->t.texdir].line_length / 4 + data->t.texx];
		len--;
		data->ray.y++;
	}
	data->ray.x++;
	return (0);
}
*/

int	draw_text(t_data *data)
{
	my_mlx_pixel_put(data, 500, 500, (int)data->text.img % 2);
	//printf("%d\n", (int)data->text.data % 2);
	//my_mlx_pixel_put(data, 500, 501, (int)data->text.data);
	//my_mlx_pixel_put(data, 501, 501, (int)data->text.data);
	//my_mlx_pixel_put(data, 501, 500, (int)data->text.data);
	return (0);
}

int color_textures(int i)
{
	int c;

	c = 0xff0000;
	if (i == 1)
		c = 0xffd700;
	return (c);
}

int	draw_3D(t_data *data, int color)
{
	double	len;
	double	start;
	double	i;
	double	x;
	double	y_step;
	double	offset;

	i = 0;
	offset = 0;
	len = data->height / data->ray.lengthf;
	y_step = data->text.height/len;
	if (len > data->height)
	{
		offset = (len - data->height)/2;
		len = data->height;
	}
	start = (data->height / 2) - (len / 2);
	data->ray.y = 0;
	while (i < start)
	{
		my_mlx_pixel_put(data, data->ray.x, data->ray.y, data->color_sky);
		i++;
		data->ray.y++;
	}
	//data->text.texy = offset*y_step;
	if (data->ray.side == 0)
	{
		x = (int)(data->ray.VsideDistY) % data->text.width;
		if (data->ray.angle > (PI / 2) && data->ray.angle < ((3 * PI) / 2))
			x = data->text.width - 1 - x;
	}
	else
	{
		x = (int)(data->ray.VsideDistX) % data->text.width;
		if (!(data->ray.angle > PI && data->ray.angle < (2 * PI)))
			x = data->text.width - 1 - x;
	}
	data->text.texx = x;
	data->text.texpos = (data->ray.y + (data->ray.y + len) / 2 + len / 2) * y_step;
	while (len > 0 && i < data->height)
	{
		/*
		texture[0].addr = (int *)mlx_get_data_addr(texture[0].data, &texture[0].bits_per_pixel, &texture[0].line_length, &texture[0].endian);
		data.addr[y * recup->data.line_length / 4 + x] = texture[0].addr[texy * texture[0].line_length / 4 + texx];

		data->text.addr = mlx_get_data_addr(data->text.data, &data->text.bpp, &data->text.line_length, &data->text.end);
		data.addr[y * data.line_length / 4 + x] = data->text.addr[data->text.texy * data->text.line_length / 4 + data->text.texx];
		*/
		data->text.texy = data->text.texpos & (data->text.height - 1);
		data->text.texpos += y_step;
		data->addr[(int)data->ray.y * data->line_length + ((int)data->ray.x * 4)] = data->text.addr[data->text.texy * data->text.line_length / 4 + data->text.texx];
		//color = color_textures(textures[(int)y * 32 + (int)x]);
		//my_mlx_pixel_put(data, data->ray.x, data->ray.y, color);
		len--;
		i++;
		//data->text.texy += y_step;
		data->ray.y++;
	}
	data->ray.x++;
	if (!color)
		return (0);
	return (0);
}

int	print_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			printf("%c", data->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}

int	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '1')
				big_pixel(data, 0x000000FF, (((x + 1) * data->cellsize) - data->cellsize), ((y + 1) * data->cellsize), data->cellsize);
			else
				big_pixel(data, 0x007F7F7F, (((x + 1) * data->cellsize) - data->cellsize), ((y + 1) * data->cellsize), data->cellsize);
			y++;
		}
		x++;
	}
	return (0);
}
