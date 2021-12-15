/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:46:45 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:46:46 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return (&((char *)s)[i]);
	}
	while (s[i] != '\0')
	{
		if (((char *)s)[i] == ((char)c))
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
