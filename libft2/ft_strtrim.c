/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:48:22 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:48:23 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_checkstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] != set[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static size_t	ft_checkend(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (len > 0 && set[i])
	{
		if (s1[len] != set[i])
			i++;
		else
		{
			len--;
			i = 0;
		}
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	len;
	int		x;
	size_t	a;

	if ((!s1) || (!set))
		return (NULL);
	i = ft_checkstart(s1, set);
	len = ft_checkend(s1, set);
	a = len;
	if (len > i)
		a = len - i;
	new = malloc((sizeof(char)) * (a + 2));
	if (!new)
		return (NULL);
	x = 0;
	while (s1[i] && i <= len)
	{
		new[x] = s1[i];
		x++;
		i++;
	}
	new[x] = '\0';
	return (new);
}
