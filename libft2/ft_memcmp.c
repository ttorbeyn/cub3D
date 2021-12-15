/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:44:36 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:44:39 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (i < n)
	{
		a = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (a)
			return (a);
		i++;
	}
	return (a);
}
