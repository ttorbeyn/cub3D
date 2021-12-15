/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:48:07 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:48:08 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (needle[x] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0' && x < len)
	{
		y = 0;
		while (haystack[x + y] == needle[y] && (x + y) < len)
		{
			y++;
			if (needle[y] == '\0')
				return (&((char *)haystack)[x]);
		}
		x++;
	}
	return (NULL);
}
