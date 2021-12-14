/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:09:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/14 05:09:17 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	check_text(t_data *data)
{
	if (data->parsing.text_no == NULL || data->parsing.text_so == NULL
		|| data->parsing.text_ea == NULL || data->parsing.text_we == NULL
		|| data->parsing.text_c == -1 || data->parsing.text_f == -1)
		return (print_error(5));
	return (0);
}

int	get_color(int i, char *str, t_data *data)
{
	int	c;

	i++;
	while (is_space(str[i]))
		i++;
	if (ato3i(&str[i], &data->r, &data->g, &data->b))
		return (-1);
	c = ft_rgb_to_trgb(0, data->r, data->g, data->b);
	if (data->r < 0 || data->r > 255 || data->g < 0
		|| data->g > 255 || data->b < 0 || data->b > 255)
		return (-1);
	return (c);
}

char	*get_path_text(int i, char *str)
{
	char	*text;

	text = NULL;
	i += 2;
	while (is_space(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
	{
		text = ft_strdup(&str[i]);
	}
	else
		return (NULL);
	return (text);
}

int	parsing_text(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O' && data->parsing.c++)
		data->parsing.text_no = get_path_text(i, str);
	else if (str[i] == 'S' && str[i + 1] == 'O' && data->parsing.c++)
		data->parsing.text_so = get_path_text(i, str);
	else if (str[i] == 'W' && str[i + 1] == 'E' && data->parsing.c++)
		data->parsing.text_we = get_path_text(i, str);
	else if (str[i] == 'E' && str[i + 1] == 'A' && data->parsing.c++)
		data->parsing.text_ea = get_path_text(i, str);
	else if (str[i] == 'F' && data->parsing.c++)
		data->parsing.text_f = get_color(i, str, data);
	else if (str[i] == 'C' && data->parsing.c++)
		data->parsing.text_c = get_color(i, str, data);
	else if (data->parsing.c == 7 && str[i] == '1')
		return (2);
	else if (!strchr("NSWEFC\0", str[i]))
		return (1);
	return (0);
}

int	recup_text(t_data *data)
{
	int		c;
	int		ret;
	char	*recup;
	size_t	len;
	int		p;

	len = 0;
	ret = 1;
	c = 0;
	while (ret == 1)
	{
		ret = get_next_line(data->fd, &recup);
		p = parsing_text(recup, data);
		if (!p && !len)
			data->parsing.map_line++;
		else if (p == 2)
		{
			if (ft_strlen(recup) > len)
				len = ft_strlen(recup);
			c++;
		}
		else
			return (print_error1(12));
		free(recup);
	}
	data->map_height = c;
	data->map_width = len;
	close(data->fd);
	return (0);
}
