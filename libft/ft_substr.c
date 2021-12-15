/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:48:29 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:48:30 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	unsigned int	c;

	i = 0;
	if (!s)
		return (NULL);
	c = len;
	if (start >= ft_strlen(s))
	{
		len = 0;
		c = 0;
	}
	else if ((start + len) > ft_strlen(s))
		c = ft_strlen(s) - start;
	new = malloc(sizeof(char) * (c + 1));
	if (!new)
		return (NULL);
	while (s[start] && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
