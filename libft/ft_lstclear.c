/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:20:36 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:43:22 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*temp;

	temp = *lst;
	if (lst && temp)
	{
		while (temp)
		{
			aux = temp->next;
			ft_lstdelone(temp, del);
			temp = aux;
		}
	}
	*lst = 0;
}
