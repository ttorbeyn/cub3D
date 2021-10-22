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

int get_text(t_data *data)
{
	char *path = "./textures/eagle.xpm";
	data->text.img = mlx_xpm_file_to_image(data->mlx, path, &data->text.width, &data->text.height);
	data->text.addr = (int *)mlx_get_data_addr(data->text.img, &data->text.bpp, &data->text.line_length, &data->text.end);
	return (0);
}

int	make_image(t_data *data)
{
	get_text(data);
	raycasting(data);
	big_pixel(data, 0x00FF0000, (data->px - (data->userheight / 2)),
		(data->py + (data->userheight / 2)), data->userheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	//mlx_put_image_to_window(data->mlx, data->mlx_win, data->text.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	//configure les parametres de base
	set_data(&data);
	//remets a 0 toutes les keys
	set_key(&data);
	/*
	if (ac < 2 || ac > 3)
	{
		printf("ERROR ARG\n");
		return (0);
	}*/
	if (!av || !ac)
		return (0);
	if (parsing(&data) == 1)
	{
		printf("ERROR MAP\n");
		return (0);
	}
	print_minimap(&data);
	//Creation d'une fenetre qui va acceuillir les pixels qu'on imprime dessus
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "cub3D");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.end);
	//Ecriture des pixels dans la fenetre
	make_image(&data);
	//Gestion des touches
	mlx_hook(data.mlx_win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_released, &data);
	mlx_hook(data.mlx_win, 17, 0L, close_window, &data);
	//Boucle pour prendre en compte les touches en continu
	mlx_loop_hook(data.mlx, deal_key, &data);
	//Boucle pour rafraichir la page en continu
	mlx_loop(data.mlx);
}
