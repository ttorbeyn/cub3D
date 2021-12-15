/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:46:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/12 18:46:15 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		n2 = -n;
		ft_putchar_fd('-', fd);
	}
	else
		n2 = n;
	if (n2 > 9)
	{
		ft_putnbr_fd((n2 / 10), fd);
		ft_putchar_fd(((n2 % 10) + '0'), fd);
	}
	else
		ft_putchar_fd((n2 + '0'), fd);
}
