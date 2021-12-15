/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:44:55 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/02/26 14:47:07 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (((unsigned char *)src) == 0 && ((unsigned char *)dst) == 0)
		return (NULL);
	if (((unsigned char *)src) == ((unsigned char *)dst))
		return (dst);
	if (((unsigned char *)src) < ((unsigned char *)dst))
	{
		i = len;
		while (i > 0)
		{
			(((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1]);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			i++;
		}
	}
	return (dst);
}
