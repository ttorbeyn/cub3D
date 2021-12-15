/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:44:03 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:44:04 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] != ((unsigned char)c))
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		else
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}
