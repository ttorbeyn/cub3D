/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:08:42 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:08:43 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

/*

	Check si le ficher a un nom
	Check si le ficher a la bonne extension (.cub)
	Check si le ficher n'est pas un dossier
 	Check si le fichier s'ouvre

*/

int	check_file(t_data *data, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (print_error(1));
	if (file[len - 1] != 'b' && file[len - 2] != 'u'
		&& file[len - 3] != 'c' && file[len - 4] != '.')
		return (print_error(2));
	data->fd = open(file, O_DIRECTORY);
	if (data->fd != -1)
		return (print_error(3));
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (print_error(4));
	return (0);
}

int	parsing(t_data *data, char *file)
{
	if (check_file(data, file))
		return (1);
	if (recup_text(data))
		return (1);
	if (check_text(data))
		return (1);
	if (recup_map(data, file))
		return (1);
	if (check_map(data))
		return (1);
	return (0);
}
