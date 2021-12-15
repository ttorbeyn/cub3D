/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:42:17 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:42:20 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size * count);
	if (!new)
		return (NULL);
	while (i < (count * size))
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
