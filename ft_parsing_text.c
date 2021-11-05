#include "cub3D.h"

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
/*
char	*convert_to_hexa(char *str)
{
	int nbr;
	char *base = "0123456789ABCDEF";
	int len = 16;
	char *text;
	int i;


	nbr = atoi(str);
	text = malloc(100);
	if (nbr == 0)
	{
		text = "00";
		return (text);
	}
	//printf("%d\n", nbr);
	i = 0;
	while (nbr >= len)
	{
		text[i] = base[nbr % len];
		//printf("text\t|%c|\n", text[i]);
		//printf("base\t|%c|\n",  base[nbr % len]);
		nbr = nbr / len;
	//	printf("%d\n", nbr);

		i++;
	}
	text[i++] = base[nbr];
	text[i] = '\0';
	text = ft_revstr(text);

	return(text);
}
*/


int get_color(int i, char *str)
{
	int color = 0;
	int c = 0;

	i++;
	printf("%s\n", str);
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] != ',' && c < 5)
		{
			printf("color\t|%d|\n", color);
			printf("str[i]\t|%d|\n", str[i] - 48);
			color = (color * 10) + (str[i] - 48);
			i++;
			c++;
			//printf("%d\n", color);
		}
		if (str[i] == ',')
			i++;
		else
			return (0);
	}
	printf("%d\n", color);
	return (color);
}

char	*get_texture(int i, char *str)
{
	char *text = NULL;

	i += 2;
	//printf("1%s\n", &str[i]);

	while (is_space(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
	{
		text = ft_strdup(&str[i]);
	}
	else
		return (NULL);
	//printf("TEXT\t|%s|\n", text);

	return (text);
}

int	check_texture(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		//printf("|%c|\n", str[i]);
		while(is_space(str[i]))
			i++;
		//printf("|%c|\n", str[i]);
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
			data->parsing.text_f = get_color(i, str);
			i++;
		}
		else if (str[i] == 'C')
		{
			data->parsing.text_c = get_color(i, str);
			i++;
		}
		else
		{
			//printf("|%c|\n", str[i]);
			//return (1);
			break;
		}
		//i++;
	}
	return (0);
}

int	recup(char *file, t_data *data)
{
	int ret;
	int fd;
	char *recup;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &recup);
		if(check_texture(recup, data))
			return (1);
	}
	printf("NO|%s|\n", data->parsing.text_no);
	printf("SO|%s|\n", data->parsing.text_so);
	printf("WE|%s|\n", data->parsing.text_we);
	printf("EA|%s|\n", data->parsing.text_ea);
	printf("F|%d|\n", data->parsing.text_f);
	printf("C|%d|\n", data->parsing.text_c);

	//printf("hello i am here\n");

	return (0);
}

int get_text(t_data *data)
{
	char *path = "./textures/eagle.xpm";
	data->text.img = mlx_xpm_file_to_image(data->mlx, path, &data->text.width, &data->text.height);
	data->text.addr = (int *)mlx_get_data_addr(data->text.img, &data->text.bpp, &data->text.line_length, &data->text.end);
	return (0);
}