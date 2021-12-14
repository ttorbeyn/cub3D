#include "includes/cub3D.h"

int	ft_rgb_to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ato3i(char *str, int *a, int *b, int *c)
{
	int	i;

	i = 0;
	if (a)
	{
		if (str[i] && !ft_isdigit(str[i]))
			return (1);
		*a = ft_atoi(&str[i++]);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	if (b)
	{
		if (str[i] && str[i] == ',')
			i++;
		if (str[i] == '\0' || !ft_isdigit(str[i]))
			return (1);
		*b = ft_atoi(&str[i++]);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	if (c)
	{
		if (str[i] && str[i] == ',')
			i++;
		if (str[i] == '\0' || !ft_isdigit(str[i]))
			return (1);
		*c = ft_atoi(&str[i]);
	}
	return (0);
}

int	get_img_text(t_data *data)
{
	data->text[0].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_no,
			&data->text[0].width, &data->text[0].height);
	if (!data->text[0].img)
		return (1);
	data->text[1].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_so,
			&data->text[1].width, &data->text[1].height);
	if (!data->text[1].img)
		return (1);
	data->text[2].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_we,
			&data->text[2].width, &data->text[2].height);
	if (!data->text[2].img)
		return (1);
	data->text[3].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_ea,
			&data->text[3].width, &data->text[3].height);
	if (!data->text[3].img)
		return (1);
	get_addr_text(data);
	return (0);
}

int	get_addr_text(t_data *data)
{
	data->text[0].addr = (int *)mlx_get_data_addr(data->text[0].img,
			&data->text[0].bpp, &data->text[0].line_length, &data->text[0].end);
	data->text[1].addr = (int *)mlx_get_data_addr(data->text[1].img,
			&data->text[1].bpp, &data->text[1].line_length, &data->text[1].end);
	data->text[2].addr = (int *)mlx_get_data_addr(data->text[2].img,
			&data->text[2].bpp, &data->text[2].line_length, &data->text[2].end);
	data->text[3].addr = (int *)mlx_get_data_addr(data->text[3].img,
			&data->text[3].bpp, &data->text[3].line_length, &data->text[3].end);
	return (0);
}
