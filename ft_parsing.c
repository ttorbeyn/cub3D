#include "cub3D.h"



char	*get_texture(int i, char *str)
{
	char *text = NULL;

	i++;
	while (is_space(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
	{
		i += 2;
		text = ft_strdup(&str[i]);
	}
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
			data->parsing.text_no = get_texture(i, str);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			data->parsing.text_so = get_texture(i, str);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			data->parsing.text_we = get_texture(i, str);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			data->parsing.text_ea = get_texture(i, str);
		else
			return (1);
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
		if(check_texture(recup, data) == 1 || check_map(data) == 1)
			return (1);
	}
	return (0);
}

int	parsing(t_data *data)
{
	if (check_coordinate(data) || check_map(data))
		return (1);
	return (0);
}