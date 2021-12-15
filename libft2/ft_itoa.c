/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:43:17 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/18 11:10:54 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_revstr(char *str)
{
	char	swp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		swp = str[i];
		str[i] = str[len];
		str[len] = swp;
		i++;
		len--;
	}
	return (str);
}

static int	ft_countdigit(int x)
{
	size_t	c;

	c = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 10;
		c++;
	}
	return (c);
}

static int	ft_isnegative(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*ft_itoa(int n)
{
	char			*new;
	int				i;
	int				c;
	unsigned int	n2;

	c = ft_countdigit(n);
	if (n < 0)
		(n2 = -n);
	else
		(n2 = n);
	new = malloc(sizeof(char) * (c + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < c)
	{
		new[i++] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	if (ft_isnegative(n) == -1)
		new[i++] = '-';
	new[i] = '\0';
	return (ft_revstr(new));
}
