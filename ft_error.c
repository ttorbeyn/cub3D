/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:08:14 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:16 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	ft_free_data(t_data *data)
{
	int	x;

	x = 0;
	if (data->parsing.text_no)
		free(data->parsing.text_no);
	if (data->parsing.text_so)
		free(data->parsing.text_so);
	if (data->parsing.text_ea)
		free(data->parsing.text_ea);
	if (data->parsing.text_we)
		free(data->parsing.text_we);
	if (data->map)
	{
		while (data->map[x])
		{
			free(data->map[x]);
			x++;
		}
		free(data->map);
	}
	return (0);
}

int	ft_exit(t_data *data)
{
	ft_free_data(data);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->text[0].img)
		mlx_destroy_image(data->mlx, data->text[0].img);
	if (data->text[1].img)
		mlx_destroy_image(data->mlx, data->text[1].img);
	if (data->text[2].img)
		mlx_destroy_image(data->mlx, data->text[2].img);
	if (data->text[3].img)
		mlx_destroy_image(data->mlx, data->text[3].img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

int	print_error(int errnum, t_data *data)
{
	printf("Error\n");
	if (errnum == 0)
		printf("Wrong number of arguments (2 needed)\n");
	else if (errnum == 1)
		printf("File .cub has no name\n");
	else if (errnum == 2)
		printf("File has not the good extension (.cub required)\n");
	else if (errnum == 3)
		printf("File .cub is a directory\n");
	else if (errnum == 4)
		printf("File could not be open\n");
	else if (errnum == 5)
		printf("Textures or color error\n");
	else if (errnum == 6)
		printf("Invalid char in map\n");
	else if (errnum == 7)
		printf("Too many coordinates\n");
	else if (errnum == 8)
		printf("Start position missing\n");
	else if (errnum == 9)
		printf("Hole in the outline (line)\n");
	return (ft_exit(data));
}

int	print_error1(int errnum, t_data *data)
{
	printf("Error\n");
	if (errnum == 10)
		printf("Hole in the outline (column)\n");
	else if (errnum == 11)
		printf("Last line empty\n");
	else if (errnum == 12)
		printf("File error\n");
	else if (errnum == 13)
		printf("Error Texture\n");
	else if (errnum == 14)
		printf("Malloc error\n");
	return (ft_exit(data));
}
