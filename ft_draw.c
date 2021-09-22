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

int	draw_ray(t_data *img, int color)
{
	double	c;
	double	x;
	double	y;

	x = img->px;
	y = img->py;
	c = 0;
	while (c <= (img->ray.length * img->cellsize) && c < 800
		&& x > 0 && y > 0 && x < img->width && y < img->height)
	{
		my_mlx_pixel_put(img, x, y, color);
		x += (cosf(img->ray.angle));
		y += (sinf(img->ray.angle));
		c++;
	}
	return (0);
}

int	draw_text(t_data *img)
{
	double len;

	len = img->text.height / img->ray.lengthf;
	if (len >= img->text.height)
		len = img->text.height;
	img->ray.y = (img->text.height / 2) - (len / 2);
	while (len > 0)
	{
		my_mlx_pixel_put(img, img->ray.x, img->ray.y, 0x000000FF);
		//img->data.addr[y * img->data.line_length / 4 + x] = recup->texture[img->t.texdir].addr[recup->t.texy * recup->texture[img->t.texdir].line_length / 4 + img->t.texx];
		len--;
		img->ray.y++;
	}
	img->ray.x++;
	return (0);
}

int	draw_3D(t_data *img, int color)
{
	double	len;
	double	start;
	double	i;

	i = 0;
	len = img->height / img->ray.lengthf;
	if (len > img->height)
		len = img->height;
	start = (img->height / 2) - (len / 2);
	img->ray.y = 0;
	while (i < start)
	{
		my_mlx_pixel_put(img, img->ray.x, img->ray.y, img->color_sky);
		i++;
		img->ray.y++;
	}
	while (len > 0 && i < img->height)
	{
		/*
		texture[0].addr = (int *)mlx_get_data_addr(texture[0].img, &texture[0].bits_per_pixel, &texture[0].line_length, &texture[0].endian);
		data.addr[y * recup->data.line_length / 4 + x] = texture[0].addr[texy * texture[0].line_length / 4 + texx];
		*/
		img->text.addr = mlx_get_data_addr(img->text.img, &img->text.bpp, &img->text.line_length, &img->text.end);
		img.addr[y * img.line_length / 4 + x] = img->text.addr[img->text.texy * img->text.line_length / 4 + img->text.texx];

		my_mlx_pixel_put(img, img->text.texx, img->text.texx, color);
		len--;
		i++;
		img->text.texy++;
	}
	img->ray.x++;
	return (0);
}

int	print_minimap(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			printf("%c", img->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	return (0);
}

int	draw_minimap(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			if (img->map[x][y] == '1')
				big_pixel(img, 0x000000FF, (((x + 1) * img->cellsize) - (img->cellsize - 1)), ((y + 1) * img->cellsize), (img->cellsize - 1));
			else
				big_pixel(img, 0x007F7F7F, (((x + 1) * img->cellsize) - (img->cellsize - 1)), ((y + 1) * img->cellsize), (img->cellsize - 1));
			y++;
		}
		x++;
	}
	return (0);
}
