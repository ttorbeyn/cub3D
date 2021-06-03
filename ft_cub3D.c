/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:21 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/05/27 18:57:24 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_data(t_data *img)
{
	img->px = 45;
	img->py = 35;
	img->angle = PI / 2;
	img->cellsize = 10;
	img->height = 1000;
	img->width = 2000;
	img->map = ft_parsing();
	img->userheight = img->cellsize / 20;
	img->color_sky = 0x00FF00FF;
	return (0);
}

int get_text(t_data *img)
{
	char *path = "./textures/eagle.xpm";
	img->text.img = mlx_xpm_file_to_image(img->mlx, path, &img->text.width, &img->text.height);
	img->text.addr = mlx_get_data_addr(img->text.img, &img->text.bpp, &img->text.line_length, &img->text.end);
	return (0);
}


int	make_image(t_data *img)
{
	get_text(img);
	draw_minimap(img);
	raycasting(img);
	big_pixel(img, 0x00FF0000, (img->px - (img->userheight / 2)),
		(img->py + (img->userheight / 2)), img->userheight);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->text.img, 0, 0);
	return (0);
}
/*
int event(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1L << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1L << 1, key_released, img);
	mlx_loop_hook(img->mlx_win, make_image, img);
	return (0);
}
*/
int	main(void)
{
	t_data	img;

	set_data(&img);
	set_key(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.end);
	make_image(&img);
	//event(&img);
	//mlx_hook(img.mlx_win, 2, 1L << 0, deal_key, &img);
	mlx_hook(img.mlx_win, 2, 1L << 0, key_pressed, &img);
	mlx_hook(img.mlx_win, 3, 1L << 1, key_released, &img);
	mlx_loop_hook(img.mlx, deal_key, &img);
	mlx_loop(img.mlx);
}
