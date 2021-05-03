/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:49:28 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:29:05 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*pointer;

	if (count == 0 || size == 0)
	{
		count = 0;
		size = 0;
	}
	pointer = malloc(sizeof(char) * count * size);
	if (pointer)
		ft_bzero(pointer, count * size);
	return (pointer);
}
