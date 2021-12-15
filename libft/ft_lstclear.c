/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubert <ttorbeyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:08:11 by hubert            #+#    #+#             */
/*   Updated: 2021/01/15 19:08:45 by hubert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if ((!lst) || (!del) || (!(*lst)))
		return ;
	current = *lst;
	while (current != 0)
	{
		(*del)(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*lst = 0;
}
