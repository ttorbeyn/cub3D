#include "cub3D.h"

int is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == 0)
		return (1);
	return (0);
}

int	is_coordinate(char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (1);
	return (0);
}

void	fill_tab_zero(void *s, size_t n)
{
	size_t i;

	i = 0;
	//s = malloc(n * sizeof(int));
	while (i < n)
	{
		((unsigned char*)s)[i] = '0';
		i++;
	}
}

int		ft_strcmp(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_base(char *base)
{
	int i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	if (ft_strcmp(base) == 0)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base[i] >= 127)
			return (0);
		i++;
	}
	return (1);
}

int		ft_str_in_base(char str, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int y;

	i = 0;
	sign = 1;
	if (ft_check_base(base) == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	y = 0;
	while (str[i] != '\0' && ft_str_in_base(str[i], base) != -1)
	{
		y *= ft_strlen(base);
		y += ft_str_in_base(str[i], base);
		i++;
	}
	return (y * sign);
}

/*

char	*ft_itoa(int nbr)
{
	unsigned int	n;
	int				count;
	int				i;
	char			*new;
	int				sign;

	count = 0;
	sign = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -nbr;
		sign = 1;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	if (!(new = malloc((count + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (sign == 1)
		new[i++] = '-';
	new[i] = '\0';
	new = ft_revstr(new);
	return (new);
}
*/