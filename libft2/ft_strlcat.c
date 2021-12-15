/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:47:14 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:47:15 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;
	size_t	z;

	z = (ft_strlen(dst) + ft_strlen(src));
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
	{
		x = 0;
		while (dst[x] != '\0')
			x++;
		y = 0;
		while (src[y] != '\0' && (x + y) < (dstsize - 1))
		{
			dst[x + y] = src[y];
			y++;
		}
		dst[x + y] = '\0';
		return (z);
	}
}
