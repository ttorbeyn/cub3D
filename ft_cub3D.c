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


int	make_image(t_data *data)
{
	addr_text(data);
	raycasting(data);
	big_pixel(data, 0x00FF0000, (data->py - (data->userheight / 2)),
		(data->px + (data->userheight / 2)), data->userheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int check_file(char *str)
{
	int len;
	int fd;

	len = ft_strlen(str);
	if (str[len - 1] != 'b' && str[len - 2] != 'u' && str[len - 3] != 'c' && str[len - 4] != '.')
		return (1);
	fd = open(str, O_RDONLY)
	if (fd < 0)


	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	set_data(&data);
	set_key(&data);
	if (ac == 2)
	{

	}
	if (check_file(av[1]))
	{
		printf("error\n");
		return (0);
	}
	if (parsing(&data) == 1)
	{
		printf("ERROR MAP\n");
		return (0);
	}
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
