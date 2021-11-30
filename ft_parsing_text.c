#include "includes/cub3D.h"

char	*ft_revstr(char *str)
{
	size_t		i;
	int		c;
	char	*new;

	c = ft_strlen(str);
	if (!(new = malloc((c + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		new[i] = str[c - 1];
		i++;
		c--;
	}
	new[i] = '\0';
	return (new);
}

int	ft_rgb_to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int ato3i(char *str, int *a, int *b, int *c)
{
	int i;

	i = 0;
	if(a)
	{
		while(str[i] && !ft_isdigit(str[i]))
			i++;
		*a = ft_atoi(&str[i++]);
		while(str[i] && ft_isdigit(str[i]))
			i++;
	}
	if(b)
	{
		while(str[i] && !ft_isdigit(str[i]))
			i++;
		*b = ft_atoi(&str[i++]);
		while(str[i] && ft_isdigit(str[i]))
			i++;
	}
	if(c)
	{
		while(str[i] && !ft_isdigit(str[i]))
			i++;
		*c = ft_atoi(&str[i]);
	}
	return (0);
}

int get_color(int i, char *str, t_data *data)
{
	int c = 0;

	i++;
	while (is_space(str[i]))
		i++;
	ato3i(str, &data->r, &data->g, &data->b);
	c = ft_rgb_to_trgb(0, data->r, data->g, data->b);
	return (c);
}


char	*get_texture(int i, char *str)
{
	char *text = NULL;

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

int	check_texture(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		while(is_space(str[i]))
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O')
		{
			data->parsing.text_no = get_texture(i, str);
			break;
		}
		else if (str[i] == 'S' && str[i + 1] == 'O')
		{
			data->parsing.text_so = get_texture(i, str);
			break;
		}
		else if (str[i] == 'W' && str[i + 1] == 'E')
		{
			data->parsing.text_we = get_texture(i, str);
			i += 2;
			break;
		}
		else if (str[i] == 'E' && str[i + 1] == 'A')
		{
			data->parsing.text_ea = get_texture(i, str);
			i += 2;
			break;
		}
		else if (str[i] == 'F')
		{
			data->parsing.text_f = get_color(i, str, data);
			i++;
		}
		else if (str[i] == 'C')
		{
			data->parsing.text_c = get_color(i, str, data);
			i++;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}



int get_text(t_data *data)
{
	data->text[0].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_no, &data->text[0].width, &data->text[0].height);
	data->text[0].addr = (int *)mlx_get_data_addr(data->text[0].img, &data->text[0].bpp, &data->text[0].line_length, &data->text[0].end);
	data->text[1].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_so, &data->text[1].width, &data->text[1].height);
	data->text[1].addr = (int *)mlx_get_data_addr(data->text[1].img, &data->text[1].bpp, &data->text[1].line_length, &data->text[1].end);
	data->text[2].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_we, &data->text[2].width, &data->text[2].height);
	data->text[2].addr = (int *)mlx_get_data_addr(data->text[2].img, &data->text[2].bpp, &data->text[2].line_length, &data->text[2].end);
	data->text[3].img = mlx_xpm_file_to_image(data->mlx, data->parsing.text_ea, &data->text[3].width, &data->text[3].height);
	data->text[3].addr = (int *)mlx_get_data_addr(data->text[3].img, &data->text[3].bpp, &data->text[3].line_length, &data->text[3].end);

	return (0);
}