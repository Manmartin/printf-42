/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:07:08 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:57:16 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*aux;

	aux = dest;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*(unsigned char *)aux++ = *(unsigned char *)src++;
	}
	return (dest);
}
