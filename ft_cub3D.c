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

#include "includes/cub3D.h"

int	mlx_create(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height,
			"cub3D");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->end);
	return (0);
}

int	make_image(t_data *data)
{
	addr_text(data);
	raycasting(data);
	big_pixel(data, 0x00FF0000, (data->py - (data->userheight / 2)),
		(data->px + (data->userheight / 2)), data->userheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	mlx_key(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_released, data);
	mlx_hook(data->mlx_win, 17, 0L, close_window, data);
	mlx_loop_hook(data->mlx, deal_key, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error(0));
	set(&data);
	if (parsing(&data, av[1]))
		return (0);
	mlx_create(&data);
	make_image(&data);
	mlx_key(&data);
}
